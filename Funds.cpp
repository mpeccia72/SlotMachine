
#include "Funds.h"

// constructor
Funds::Funds() {
    balance = 0;
    credits = 0;
}

// deducts input from credit total
bool Funds::deductCredits(int x) {

    // makes sure credits don't go negative
    if(credits - x < 0) return false;

    // deducts credits
    credits -= x;
    return true;

}

// adds credits
void Funds::addCredits(int x) {
    credits += x;
}