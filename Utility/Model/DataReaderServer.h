#ifndef ED1_DATAREADERSERVER_H
#define ED1_DATAREADERSERVER_H

#include <cstring>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>
#include <thread>
#include <iostream>
#include "SampleTable.h"
#include "DataReaderServer.h"

#define MILLISECONDS_IN_SECOND 1000

using namespace std;

// Every class want to pass data to server, will use this struct.
struct PassServerData {
    // Port number and reading rate.
    uint16_t port;
    int readForSecond = MILLISECONDS_IN_SECOND;
};

struct PassProgramData {
    PassServerData serverData;
    pthread_cond_t *serverCond;
};

void *OpenReadingServer(void *arg);

#endif //ED1_DATAREADERSERVER_H
