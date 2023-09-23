
#include "RandomState.h"

RandomState::RandomState() {

    for(int i = 0; i < 1000; i++) {

        // seeding
        srand(time(0) + i);
        
        // generate 0 - 20 odds
        int rand1 = rand()%20;

        // if 14 hits, the machine will shift to a higher payout state for a random amount of time
        if(rand1 == 19) {

            // new seeding
            srand(time(0) + i*i);

            // generates 0 - 11 odds
            int rand2 = rand()%12;

            for(int j = 0; j < rand2; j++) {
                state[i] = 1;
                i++;
            }

        }

        else {
            state[i] = 0;
        }

    }

}

int RandomState::getNextState() {
    return state[index++];
}