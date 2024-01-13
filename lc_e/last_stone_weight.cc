#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int x, y;

    while(stones.size() > 1){
        sort(stones.begin(), stones.end());
        y = stones.back();
        stones.pop_back();
        x = stones.back();
        stones.pop_back();
        if(x != y){
            stones.push_back(y-x);
        }
    }
    return stones.size() == 0 ? 0 : stones[0];
}

int main() {
    // vector<int> stones{2, 7, 4, 1, 8, 1};
    vector<int> stones{2, 2};
    cout << lastStoneWeight(stones);

}