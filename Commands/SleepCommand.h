
#ifndef ED1_SLEEPCOMMAND_H
#define ED1_SLEEPCOMMAND_H

#include "Command.h"
#include <thread>

#define SINGLE_VALUE 1
#define TIME_POSITION 0

/**
 * Sleep command, no need for cpp file, use simple sleeping command.
 */
class SleepCommand : public Command {

    int milliseconds;

public:

    /**
     * Construct sleep command use string with time data.
     * @param time - for waiting in miliseconds.
     */
    explicit SleepCommand(const string &time) {
        try {
            // Check for valid value.
            if (checkValid(vector<string>{time})) {

                this->milliseconds = stoi(time);
            } else {
                throw invalid_argument("Negative time is not valid.");
            }

        } catch (...) {
            throw invalid_argument("Problem in sleeping values command.");
        }
    }

    /**
     * Execute the command, sleep command.
     */
    void doCommand() override {

        this_thread::sleep_for(chrono::milliseconds(this->milliseconds));
    }

/**
 * Check valid sleeping value.
 * @param data - list of data strings(single data value).
 * @return - true if valid, other wise false.
 */
    bool checkValid(const vector<string> &sleepString) const override {

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
