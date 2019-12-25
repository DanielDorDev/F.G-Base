#include "VarCommand.h"


BindCommand *VarCommand::getBind() const {
    if (this->bind == nullptr) {
        throw runtime_error("no bind");
    } else {
        return this->bind;
    }
}


/**
 * Set var command.
 * @param bindSet - bind to set by, and a name of variable.
 * @param name, name of the variable.
 */
VarCommand::VarCommand(BindCommand *bindSet) :
        bind(bindSet) {
}


VarCommand::VarCommand(double bindSet) {
    this->value = bindSet;
}

/**
* @return - the value of the variable.
*/
double VarCommand::getValue() const {
  if (this->bind == nullptr || !SampleTable::getSingletonInstance().checkExist(this->bind->getBindPath())) {
    return this->value;
  } else {
    return this->bind->getValue();
  }
}

/**
 * Change var command by given direct double value.
* @param - double value.
 * @return - VarCommand changed.
 */
VarCommand &VarCommand::operator=(double setValue) {
    if (this->bind == nullptr) {
        this->value = setValue;
    } else {
        this->bind->set(setValue);
    }
    return *this;
}

/**
* Change var command by given another var command with a value inside.
* @param - Var command with value.
* @return - VarCommand changed.
*/
VarCommand &VarCommand::operator=(const VarCommand &variable) {

    if (this->bind == nullptr) {
        this->value = variable.getValue();
    } else {
        this->bind->set(variable.getValue());
    }
    return *this;
}

/**
* Change var command by given path, bind it to the path.
* @param - bind command with a path to set the VarCommand.
* @return - VarCommand changed.
*/
VarCommand &VarCommand::operator=(BindCommand *bind) {
    this->bind = bind;
    return *this;
}


void VarCommand::doCommand() {

}

bool VarCommand::checkValid(const vector<string> &vector1) const {
    return false;
}

VarCommand::~VarCommand() {
    if (this->bind != nullptr) {
        delete (this->bind);
    }

}


