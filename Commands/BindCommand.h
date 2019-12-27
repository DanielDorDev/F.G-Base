
#ifndef ED1_BINDCOMMAND_H
#define ED1_BINDCOMMAND_H

#include "ConnectCommand.h"
#include "../Utility/Model/SampleTable.h"

class BindCommand {

    // Path of the bind.
    string path;

    // Binding socket.
    const ConnectCommand *connectedSocket;

    // Point to the static table.
    SampleTable *table;

public:
////////////////
    /**
   * Bind command constructors, use connected socket and string
     */
    explicit BindCommand(ConnectCommand *, string &);

    /**
   * Bind command constructors, use connected socket and const char*
   */
    explicit BindCommand(ConnectCommand *, const char *);

    /**
     * @return - string with path which bind.
     */
    string getBindPath() const;

    /**
     * Change value by sending client massage.
     */
    void set(double) const;

    double getValue() const;

    void changePath(const std::string &setPath);

    BindCommand &operator=(const BindCommand &);
};

#endif //ED1_BINDCOMMAND_H
