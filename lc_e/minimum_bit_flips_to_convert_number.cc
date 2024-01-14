#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    int pos = 0, count=0;

    for(pos=0; pos<32; pos++){
        if((start & (1 << pos)) == (goal & (1 << pos))) {
            continue;
        }   else {
            start ^= (1 << pos);
            count++;
        }
    }

    return count;
}

int main() {
    // int start = 10;
    // int goal = 7;

    // int start = 3;
    // int goal = 4;

    // int start = 3;
    // int goal = 3;

    int start = 0;
    int goal = 7;
    cout << minBitFlips(start, goal);
}