
#include "BindCommand.h"

#define SPACE " "
#define MSG_PREFIX "set "
#define MSG_SUFFIX " \r\n"

BindCommand::BindCommand(ConnectCommand *socketToConnect, const char *setPath) {
    if (socketToConnect == nullptr) {
        throw invalid_argument("Need to have connection");
    }
    this->path = setPath;
    this->table = &SampleTable::getSingletonInstance();
    this->connectedSocket = socketToConnect;
}

BindCommand::BindCommand(ConnectCommand *socketToConnect, string &setPath) {
    if (socketToConnect == nullptr) {
        throw invalid_argument("Need to have connection");
    }
    this->path = setPath;
    this->table = &SampleTable::getSingletonInstance();
    this->connectedSocket = socketToConnect;
}


void BindCommand::changePath(const std::string &setPath) {
    this->path = setPath;
}

double BindCommand::getValue() const {
    return this->table->getSample(this->path);
}

void BindCommand::set(double value) const {
    string preMessage = MSG_PREFIX;
    preMessage += this->path;
    (preMessage += SPACE) += to_string((value)) += SPACE;
    preMessage += MSG_SUFFIX;
    this->connectedSocket->sendMassage(preMessage);
    if (this->table->checkExist(this->path)) {
        this->table->doSingleUpdate(this->getBindPath(), value);
    }
}

/**
 * @return - string with path which bind.
 */
string BindCommand::getBindPath() const {
    return this->path;
}

BindCommand &BindCommand::operator=(const BindCommand &bindCopy) {

    this->path = bindCopy.getBindPath();
    return *this;
}



