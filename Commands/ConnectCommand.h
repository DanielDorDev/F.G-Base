#ifndef ED1_CONNECTCOMMAND_H
#define ED1_CONNECTCOMMAND_H
#define NOT_INITIALIZED (-1)

#include "ICommand.h"
#include "../Utility/Model/ClientWriter.h"

class ConnectCommand : public ICommand {

    int socketFd = NOT_INITIALIZED;
    ConnectData *connectData;

/**
 * Check valid for ip and port number.
 * @param data - list of data strings.
 * @return - true if valid, other wise false.
 */
    bool checkValid(const vector<string> &) const override;

public:

    explicit ConnectCommand(const vector<string> &);

    /**
     * Execute the command, connect to flight gear as client.
     * @param data - ip and port.
     */
    void doCommand() override;

    void sendMassage(string &) const;

    ~ConnectCommand();
};

#endif