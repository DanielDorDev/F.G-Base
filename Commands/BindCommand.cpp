
#include "BindCommand.h"

#define SPACE " "
#define MSG_PREFIX "set "
#define MSG_SUFFIX " \r\n"

BindCommand::BindCommand(ConnectCommand *socketToConnect, const char *setPath) {
    if (socketToConnect == nullptr) {
        throw invalid_argument("Need to have connection");
    }
    path = setPath;
    table = &SampleTable::getSingletonInstance();
    connectedSocket = socketToConnect;
}

BindCommand::BindCommand(ConnectCommand *socketToConnect, string &setPath) {
    if (socketToConnect == nullptr) {
        throw invalid_argument("Need to have connection");
    }
    path = setPath;
    table = &SampleTable::getSingletonInstance();
    connectedSocket = socketToConnect;
}


void BindCommand::changePath(const std::string &setPath) {
    path = setPath;
}

double BindCommand::getValue() const {
    return table->getSample(path);
}

void BindCommand::set(double value) const {
    string preMessage = MSG_PREFIX;
    preMessage += path;
    (preMessage += SPACE) += to_string((value)) += SPACE;
    preMessage += MSG_SUFFIX;
    connectedSocket->sendMassage(preMessage);
    if (table->checkExist(path)) {
        table->doSingleUpdate(getBindPath(), value);
    }
}

/**
 * @return - string with path which bind.
 */
string BindCommand::getBindPath() const {
    return path;
}

BindCommand &BindCommand::operator=(const BindCommand &bindCopy) {

    path = bindCopy.getBindPath();
    return *this;
}



