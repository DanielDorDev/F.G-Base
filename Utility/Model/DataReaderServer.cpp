
#include "DataReaderServer.h"

#define FLIGHT_EXIT "FlightGear has disconnected"
#define BUFFER_SIZE 256
#define MAX_CLIENTS 1
#define END_OF_PACKET '\n'


/**
 * Execute server opening.
 */


void *OpenReadingServer(void *arg) {


  SampleTable* sampleTable = &SampleTable::getSingletonInstance();

    bool connectedToFlight = false;

    // Open data from calling thread.
    auto *argData = (struct PassProgramData *) arg;

    // Data from the socket.
    int sockfd, newSockFd, clilen;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in serverAdd, cli_addr;
    ssize_t n;

    // First call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    try {
        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        // Initialize socket structure
        bzero((char *) &serverAdd, sizeof(serverAdd));

        serverAdd.sin_family = AF_INET;
        serverAdd.sin_addr.s_addr = INADDR_ANY;
        serverAdd.sin_port = htons(argData->serverData.port);

        // Now bind the host address using bind() call.
        if (bind(sockfd, (struct sockaddr *) &serverAdd, sizeof(serverAdd)) <
            0) {
            perror("ERROR on binding");
            exit(1);
        }

        //Listening for the clients, wait for incoming massage.
        listen(sockfd, MAX_CLIENTS);
        clilen = sizeof(cli_addr);

        // Accept actual connection from the client
        newSockFd =
                accept(sockfd, (struct sockaddr *) &cli_addr,
                       (socklen_t *) &clilen);

        // If accept data failed.
        if (newSockFd < 0) {
            perror("Error on accept data");
            exit(1);
        }

        // If connection is established then start communicating.
        string bufferLink, reminder;
        // Server main operation.
        do {

            // Clean buffer.
            bzero(buffer, BUFFER_SIZE);

            // Data receive.
            n = read(newSockFd, buffer, BUFFER_SIZE - 1);
            // Buffer for sending.
            bufferLink.append(buffer);

            unsigned long sendUntil = bufferLink.find(END_OF_PACKET);


            // Update sample table.
            sampleTable->doFullUpdate(bufferLink.substr(0, sendUntil));

            bufferLink.erase(0, sendUntil + 1);

            if (!connectedToFlight) {
                connectedToFlight = true;
                pthread_cond_signal(argData->serverCond);
            }

            if (n < 0) {
                perror("Error reading from server");
                exit(1);
            }
            this_thread::sleep_for(
                    chrono::milliseconds(argData->serverData.readForSecond));

        } while (n != 0);
        cout << FLIGHT_EXIT << endl;
        exit(0);
    } catch (...) {
        exit(1);
    }
}
