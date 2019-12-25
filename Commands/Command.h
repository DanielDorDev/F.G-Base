#ifndef ED1_COMMAND_H
#define ED1_COMMAND_H

#include <iostream>
#include <vector>

#define SYNTAX_ERROR "Can't execute the command "
using namespace std;


/**
 * Command will be used as allocated class.
 *The the purpose is to add option for history commands.
 */
class Command {

    /**
     * Check if command have valid data.
     * @return - true if valid, else false.
     */
    virtual bool checkValid(const vector<string> &) const = 0;

public:

    /**
      * Execute a command.
      * @param data - list of data for every command.
      */
    virtual void doCommand() = 0;

    virtual ~Command() = default;
};


#endif //ED1_COMMAND_H

