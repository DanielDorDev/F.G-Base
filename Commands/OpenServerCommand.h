#ifndef ED1_OPENSERVERCOMMAND_H
#define ED1_OPENSERVERCOMMAND_H

#include <vector>
#include "../Utility/Interface/ICommand.h"
#include "../Utility/Model/DataReaderServer.h"

class OpenServerCommand : public ICommand {

    // Data to pass reader.
    PassProgramData *data;

    bool checkValid(const std::vector<std::string> &) const ;

public:


    explicit OpenServerCommand(const vector<string> &);


    void doCommand() override;

    ~OpenServerCommand() override;
};

#endif //ED1_OPENSERVERCOMMAND_H
