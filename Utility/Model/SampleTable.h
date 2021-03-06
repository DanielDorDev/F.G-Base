#ifndef ED1_SAMPLETABLE_H
#define ED1_SAMPLETABLE_H
#define XML_SAMPLE_SIZE 23

#include <array>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <string>

// Sample name enum, for easy and comfortable use.
enum SampleName {
    INDICATED_SPEED_KT, ALT_INDICATED_ALTITUDE_FT,
    ALT_PRESSURE_ALT_FT, INDICATED_PITCH_DEG,
    INDICATED_ROLL_DEG, INTERNAL_PITCH_DEG,
    INTERNAL_ROLL_DEG, INDICATED_ALTITUDE_FT,
    ENCODER_PRESSURE_ALT_FT, ENCODER_INDICATED_ALTITUDE_FT,
    INDICATED_GROUND_SPEED_KT, INDICATED_VERTICAL_SPEED,
    INDICATOR_INDICATED_HEADING_DEG, MAGNETIC_INDICATED_HEADING_DEG,
    INDICATED_SLIP_SKID, INDICATED_TURN_RATE,
    INDICATED_SPEED_FPM, AILERON, ELEVATOR, RUDDER, FLAPS, THROTTLE, RPM
};

class SampleTable {

    // Connect between path and sample table (path is less used).
    std::unordered_map<std::string, SampleName> stringToSampleName = {
            {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                    INDICATED_SPEED_KT},
            {"/instrumentation/altimeter/indicated-altitude-ft",
                    ALT_INDICATED_ALTITUDE_FT},
            {"/instrumentation/altimeter/pressure-alt-ft",
                    ALT_PRESSURE_ALT_FT},
            {"/instrumentation/attitude-indicator/indicated-pitch-deg",
                    INDICATED_PITCH_DEG},
            {"/instrumentation/attitude-indicator/indicated-roll-deg",
                    INDICATED_ROLL_DEG},
            {"/instrumentation/attitude-indicator/internal-pitch-deg",
                    INTERNAL_PITCH_DEG},
            {"/instrumentation/attitude-indicator/internal-roll-deg",
                    INTERNAL_ROLL_DEG},
            {"/instrumentation/encoder/indicated-altitude-ft",
                    INDICATED_ALTITUDE_FT},
            {"/instrumentation/encoder/pressure-alt-ft",
                    ENCODER_PRESSURE_ALT_FT},
            {"/instrumentation/gps/indicated-altitude-ft",
                    ENCODER_INDICATED_ALTITUDE_FT},
            {"/instrumentation/gps/indicated-ground-speed-kt",
                    INDICATED_GROUND_SPEED_KT},
            {"/instrumentation/gps/indicated-vertical-speed",
                    INDICATED_VERTICAL_SPEED},
            {"/instrumentation/heading-indicator/offset-deg",
                    INDICATOR_INDICATED_HEADING_DEG},
            {"/instrumentation/magnetic-compass/indicated-heading-deg",
                    MAGNETIC_INDICATED_HEADING_DEG},
            {"/instrumentation/slip-skid-ball/indicated-slip-skid",
                    INDICATED_SLIP_SKID},
            {"/instrumentation/turn-indicator/indicated-turn-rate",
                    INDICATED_TURN_RATE},
            {"/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                    INDICATED_SPEED_FPM},
            {"/controls/flight/aileron",
                    AILERON},
            {"/controls/flight/elevator",
                    ELEVATOR},
            {"/controls/flight/rudder",
                    RUDDER},
            {"/controls/flight/flaps",
                    FLAPS},
            {"/controls/engines/current-engine/throttle",
                    THROTTLE},
            {"/engines/engine/rpm",
                    RPM}
    };

    std::array<std::string, XML_SAMPLE_SIZE> sampleTable;

  SampleTable() = default;

public:


  static SampleTable &getSingletonInstance() {
    static SampleTable instance;
    return instance;
  }


    void doFullUpdate(std::string);


    void doSingleUpdate(std::string, double);


    bool checkExist(std::string) const;


    double getSample(std::string) const;
};


#endif //ED1_SAMPLETABLE_H
