#ifndef ED1_CONNECTCOMMAND_H
#define ED1_CONNECTCOMMAND_H
#define NOT_INITIALIZED (-1)

#include <vector>
#include "../Utility/Interface/ICommand.h"
#include "../Utility/Model/ClientWriter.h"

class ConnectCommand : public ICommand {

    int socketFd = NOT_INITIALIZED;
    ConnectData *connectData;

    bool checkValid(const std::vector<std::string> &) const ;

public:

    explicit ConnectCommand(const vector<string> &);

    void doCommand() override;

    void sendMassage(string &) const;

    ~ConnectCommand() override;
};

#endif