
#include <iostream>
#include "RandomState.h"
#include "Funds.h"

using namespace std;

class Machine {

    // resonsible for machine funds 
    Funds machineFunds;

    // responsible for determining the machine expected payout state with every spin
    RandomState rngEngine;

    // payline
    int payline[3] = {0,0,0};

    // expected payout on the machine
    const float defaultExpectedPayout = .9;

    float tunedPayout = 1;

    // combination odds
    float state1Odds[7] = {.1,2,3,4,.03,.02,.01};
    float state2Odds[7] = {1,2,3,4,5,6,7};

    // determines payout based off payline
    void determineLinePayout();

    public:
        bool spin();

        void setExpectedPayout(float);


};