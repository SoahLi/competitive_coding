#include <iostream>
#include <vector>
using namespace std;

vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> sectors(n+1, 0);
    int i = rounds[0], j = 1, largest = 1;


    while(j < rounds.size()) {
        while(i != rounds[j]) {
            sectors[i]++;
            largest = max(largest, sectors[i]);
            i++;
            if(i > n) i = 1;
        }
        j++;
    }
    sectors[i]++;
    largest = max(largest, sectors[i]);
    i = 0;

    vector<int> result;
    while(i < sectors.size()) {
        if(sectors[i] == largest) 
            result.push_back(i);
        i++;
    }


    return result;
}

int main() {
    // vector<int> rounds{1,3,1,2};
    // rounds = mostVisited(4, rounds);

    // vector<int> rounds{2,1,2,1,2,1,2,1,2};
    // rounds = mostVisited(2, rounds);

    vector<int> rounds{1,3,5,7};
    rounds = mostVisited(7, rounds);

    for(int sector : rounds) {
        cout << sector << " ";
    }
} 