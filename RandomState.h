
#include <cstdlib>
#include <ctime>

// this class helps randomize expected payout states
// the expect payout isn't constant with every spin
class RandomState {

    int* state = new int[1000];
    int index = 0;

    public:
        RandomState();
        int getNextState();

};