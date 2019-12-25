
#ifndef ED1_CLIENTWRITER_H
#define ED1_CLIENTWRITER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

struct ConnectData {
    string serverIP;
    uint16_t portNumber;
    pthread_cond_t *serverCond;
    int *connectFD;

};

/**
 * connecting the client.
 * @param arg the argument.
 * @return the connection.
 */
void *connectClient(void *arg);

#endif //ED1_CLIENTWRITER_H
