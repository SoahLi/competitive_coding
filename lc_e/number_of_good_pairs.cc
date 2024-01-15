#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

//First Try
// int numIdenticalPairs(vector<int> nums) {
//     unordered_map<int, set<int>> map;
//     for(int i=0; i<nums.size(); i++) {
//         map[nums[i]].insert(i);
//     }

//     int count = 0, n;
//     for(auto& s : map){
//         n = s.second.size();
//         for(int i=0; i<n; i++) {
//             count += (n-i);
//         }
//     }

//     return count;
// }

//Second Try: Change int i=0 to int i=1
int numIdenticalPairs(vector<int> nums) {
    unordered_map<int, set<int>> map;
    for(int i=0; i<nums.size(); i++) {
        map[nums[i]].insert(i);
    }

    int count = 0, n;
    for(auto& s : map){
        n = s.second.size();
        for(int i=1; i<n; i++) {
            count += (n-i);
        }
        // cout << endl;
    }

    return count;
}





int main() {
    // vector<int> nums{1,2,3,1,1,3};
    // vector<int> nums{`1,1,1,1};
    // vector<int> nums{1,2,3};
    vector<int> nums{1};
    
    cout << numIdenticalPairs(nums);

}