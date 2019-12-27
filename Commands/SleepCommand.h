
#ifndef ED1_SLEEPCOMMAND_H
#define ED1_SLEEPCOMMAND_H

#include "../Utility/Interface/ICommand.h"
#include "../Utility/Exception/InvalidCommand.h"
#include <thread>

#define SINGLE_VALUE 1
#define TIME_POSITION 0

class SleepCommand : public ICommand {

    int milliseconds;

public:


    explicit SleepCommand(const std::string &time) {
        try {
            // Check for valid value.
            if (checkValid(std::vector<std::string>{time})) {

                this->milliseconds = stoi(time);
            } else {
                throw InvalidCommand();
            }

        } catch (...) {
            throw InvalidCommand();
        }
    }


    void doCommand() override {

        std::this_thread::sleep_for(std::chrono::milliseconds(this->milliseconds));
    }

    bool checkValid(const std::vector<std::string> &sleepString) const  {

        try {
            // Not single value.
            if (sleepString.size() != SINGLE_VALUE) {
                return false;
            } else {
                // Check if seconds are positive(or zero).
                return (stoi(sleepString[TIME_POSITION]) >= 0);
            }
        } catch (...) {
            return false;
        }
    }
};

#endif //ED1_SLEEPCOMMAND_H
