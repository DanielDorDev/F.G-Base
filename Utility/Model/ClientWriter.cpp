
#include "ClientWriter.h"





void* connectClient(void* arg) {

  auto *argData = (struct ConnectData *) arg;
  ssize_t n;
  int sockfd;

  // Data structs define socket.
  struct sockaddr_in serv_addr;
  struct hostent *serverToConnect;

  try {
    // Open data from calling thread.



    // Create a socket point.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
    }
    serverToConnect = gethostbyname(argData->serverIP.c_str());

    if (serverToConnect == nullptr) {
      fprintf(stderr, "ERROR, no such host\n");
      exit(1);
    }

    // Clean buffer for data.
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Define the socket type.
    serv_addr.sin_family = AF_INET;

    // Copy client data pass.
    bcopy(serverToConnect->h_addr,
          (char *) &serv_addr.sin_addr.s_addr,
          (size_t) serverToConnect->h_length);
    serv_addr.sin_port = htons(argData->portNumber);
    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))
        < 0) {
      perror("ERROR connecting");
      exit(1);
    }
    *(argData->connectFD) = sockfd;
    // Single the main to continue his process.
    pthread_cond_signal(argData->serverCond);
    n = 1;
    do {

      if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
      }
    // Will finish when server exit.
    } while (n != 0);
  } catch (...) {
    exit(1);
  }
}

