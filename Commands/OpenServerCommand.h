#ifndef ED1_OPENSERVERCOMMAND_H
#define ED1_OPENSERVERCOMMAND_H

#include "Command.h"
#include "../Utility/Model/DataReaderServer.h"

class OpenServerCommand : public Command {

    // Data to pass reader.
    PassProgramData *data;

    /**
   * Check if command have valid data.
   * @return - true if valid, else false.
   */
    bool checkValid(const vector<string> &) const override;

public:

/**
 * Construct the open server class command.
 * @param stringData - get the data to open by.
 */
    explicit OpenServerCommand(const vector<string> &);


    /**
     * Execute the command, open server for reading information.
     * @param data - port and read for second speed(inside the list).
     */
    void doCommand() override;

    /**
   * Clean data passes.
   */
    ~OpenServerCommand() override;
};

#endif //ED1_OPENSERVERCOMMAND_H
