
#include "ConnectCommand.h"

#define CONNECT_TO_FLIGHT ", trouble in connect syntax."
#define MAX_PORT_NUMBER 65535
#define VALID_DATA_COUNT 2
#define VALID 1

enum Data {
    IP_4, PORT_TO_CONNECT
};

#include "ConnectCommand.h"


bool ConnectCommand::checkValid(const vector<string> &data) const {


    try {

        // Convert data to usable numbers, if double catch it.
        int portNumber = stoi(data[PORT_TO_CONNECT]);

        // Check if data fit the open server command.
        if (data.size() != VALID_DATA_COUNT) {
            return false;

            // Check if port number in in correct range.
        } else if (portNumber > MAX_PORT_NUMBER | portNumber < 0) {
            return false;

            // Ip check.
        } else {

            // Check using inet_pton, return 1 if valid, otherwise 0\-1.
            struct sockaddr_in sa;
            return (inet_pton(AF_INET, data[IP_4].c_str(), &(sa.sin_addr)) ==
                    VALID);
        }

    } catch (...) {
        // If problem is undefined.
        return false;
    }
}

void ConnectCommand::doCommand() {

    // Create pthread, conditional thread & mutex.

    pthread_mutex_t muClient = PTHREAD_MUTEX_INITIALIZER;
    pthread_t threadClient;
    pthread_cond_t clientConnectCond = PTHREAD_COND_INITIALIZER;

    this->connectData->serverCond = &clientConnectCond;
    pthread_mutex_lock(&muClient);
    pthread_create(&threadClient, nullptr, connectClient, this->connectData);
    pthread_cond_wait(&clientConnectCond, &muClient);
    pthread_mutex_unlock(&muClient);

    pthread_mutex_destroy(&muClient);
    pthread_cond_destroy(&clientConnectCond);

}


void ConnectCommand::sendMassage(string &massage) const {
    if (this->socketFd != NOT_INITIALIZED) {
        send(this->socketFd, massage.c_str(), massage.length(), 0);
    } else {
        perror("Not initialized connect command");
    }
}

ConnectCommand::ConnectCommand(const vector<string> &data) {

    this->connectData = new ConnectData();
    if (checkValid(data)) {


        // Save data to packet, and send it to connect class.
        this->connectData->portNumber = (uint16_t) stoi(data[PORT_TO_CONNECT]);
        this->connectData->serverIP = data[IP_4];
        this->connectData->connectFD = &this->socketFd;

    } else {
        perror("Can't execute the command " CONNECT_TO_FLIGHT);
    }

}


ConnectCommand::~ConnectCommand() {

    delete this->connectData;
}