#include "VarCommand.h"

BindCommand *VarCommand::getBind() const {
    if (this->bind == nullptr) {
        throw runtime_error("No bind");
    } else {
        return new BindCommand(*bind);
    }
}

VarCommand::VarCommand(BindCommand *bindSet) :
        bind(bindSet) {
}

VarCommand::VarCommand(double bindSet) {
    delete value;
    value = new Number(bindSet);
}

VarCommand::VarCommand() {
    value = new Number(0);
}

double VarCommand::getValue() const {
  if (this->bind == nullptr ||
  !SampleTable::getSingletonInstance().checkExist(this->bind->getBindPath())) {
    return value->calculate();
  } else {
    return this->bind->getValue();
  }
}


VarCommand &VarCommand::operator=(double setValue) {
    if (this->bind == nullptr) {
        value = new Number(setValue);
    } else {
        this->bind->set(setValue);
    }
    return *this;
}

VarCommand &VarCommand::operator=(const VarCommand &variable) {

    if (bind == nullptr) {
        value = new Number(variable.getValue());
    } else {
        bind->set(variable.getValue());
    }
    return *this;
}


VarCommand &VarCommand::operator=(BindCommand *sbind) {
    bind = sbind;
    return *this;
}




