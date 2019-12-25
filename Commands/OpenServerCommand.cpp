#include "OpenServerCommand.h"

#define OPEN_SERVER ", trouble in open server syntax."
#define MAX_PORT_NUMBER 65535
#define VALID_DATA_COUNT 2

// Type of data passed.
enum Data {
    PORT_TO_CONNECT, READS_FOR_SECOND
};


OpenServerCommand::OpenServerCommand(const vector<string> &stringData) {

    // Create a packet to send the server data.
    this->data = new PassProgramData();

    // Check valid for the data.
    if (checkValid(stringData)) {
        // Convert data to usable numbers, if double catch it.
        this->data->serverData.port = (uint16_t) stoi(
                stringData[PORT_TO_CONNECT]);

        this->data->serverData.readForSecond =
                (this->data->serverData.readForSecond /
                 stoi(stringData[READS_FOR_SECOND]));

    } else {
        throw invalid_argument("Cant open server" OPEN_SERVER);
    }
}


bool OpenServerCommand::checkValid(const vector<string> &data) const {

    try {

        // Check valid of the data, port and second time.
        int portCheck = stoi(data[PORT_TO_CONNECT]);
        int readsCheck = stoi(data[READS_FOR_SECOND]);

        // Check if data fit the open server command.
        if (data.size() != VALID_DATA_COUNT) {
            return false;

            // Check if port number in in correct range.
        } else if (portCheck > MAX_PORT_NUMBER | portCheck < 0) {
            return false;

            // If Read for seconds is positive, data is valid, return true.
        } else return readsCheck >= 0;

        // If the number is double , invalid argument.
    } catch (invalid_argument &e) {
        return false;

    } catch (...) {
        // If problem is undefined.
        return false;
    }
}


void OpenServerCommand::doCommand() {

    // Create pthread, conditional thread & mutex.

    pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    pthread_t threadServer;
    pthread_cond_t flightGearConnected = PTHREAD_COND_INITIALIZER;
    // Pass the cond for stopping the program until connection created.
    this->data->serverCond = &flightGearConnected;

    // Lock until the connection created, wait for signal.
    pthread_mutex_lock(&mu);
    pthread_create(&threadServer, nullptr, OpenReadingServer, this->data);
    pthread_cond_wait(&flightGearConnected, &mu);
    pthread_mutex_unlock(&mu);

    // Clean.
    pthread_mutex_destroy(&mu);
    pthread_cond_destroy(&flightGearConnected);
}

OpenServerCommand::~OpenServerCommand() {
    delete data;
}
