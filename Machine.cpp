#include "Machine.h"

Machine::Machine() {

}

bool Machine::spin() {

    // if machine is out of funds, there is no spin
    if(!machineFunds.deductCredits(2)) {
        return false;
    }
    
    if(rngEngine.getNextState() == 0) {
        
        srand(time(0));

        int x = rand()%1000;

        if(x < 900) {
            payline[0] = 0;
            payline[1] = 0;
            payline[2] = 0;
        }

        else if(x < 950) {
            payline[0] = 1;
            payline[1] = 1;
            payline[2] = 1;
        }

        else if(x < 970) {
            payline[0] = 6;
            payline[1] = 0;
            payline[2] = 0;
        }

        else if(x < 990) {
            payline[0] = 3;
            payline[1] = 0;
            payline[2] = 0;
        }


    }

    // the rng is in an increased payout state
    else {

    }

}

// determines what payline is worth and pays
void Machine::determineLinePayout() {

    int tripleStar = 0;
    int seven = 0;
    int bar = 0;
    bool noCombination = false;
    
    // checks for an empty slot, if slot is empty, noCombination is marked as true
    for(int i = 0; i < 3; i++) {

        switch(payline[i]) {

            case 3: tripleStar++; break;
            case 2: seven++; break; 
            case 1: bar++; break;
            default: noCombination = true; break;

        }

    }

    // example, two bars and one 7 aren't a combo
    if(bar + seven == 3) noCombination = true;

    // if there is no combination on the payline, this check to see if there are any triple stars
    if(noCombination == true) {
        switch(tripleStar) {
            case 0: break;
            case 1: machineFunds.addCredits(6); break;
            case 2: machineFunds.addCredits(50); break;
            default: break;
        }

        return; // no combination on payline, no need to continue
    }

    // there is a payline on the machine, this determines it
    if(bar == 3) machineFunds.addCredits(20);
    else if (seven == 3) machineFunds.addCredits(50);
    else if(bar == 2) machineFunds.addCredits(60);
    else if (seven == 2) machineFunds.addCredits(150);
    else if(bar == 1) machineFunds.addCredits(180);
    else if (seven == 1) machineFunds.addCredits(450);

    // jackpot
    else {
        machineFunds.addCredits(1000);
        cout << "CALL ASSISTANT!" << endl;
        int x;
        cin >> x;
    }

}

// set expected payout value on machine
void Machine::setExpectedPayout(float x) {

    tunedPayout = x/defaultExpectedPayout;

    for(int i = 0; i < 7; i++) {
        state1Odds[i] = tunedPayout * state1Odds[i];
        state2Odds[i] = tunedPayout * state2Odds[i];
    }

}