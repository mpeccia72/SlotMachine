#include <iostream>
#include "RandomState.h"

using namespace std;

int main() {

    RandomState obj;

    for(int i = 0; i < 1000; i++) {
        cout << obj.getNextState() << " ";
    }

    int x;
    cin >> x;

}

// @@@
// @7@
// @77
// 