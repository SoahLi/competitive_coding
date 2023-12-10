#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){
    unordered_set<int> vals;
    for(int num: nums)
        vals.insert(num);
    int result = 0;
    for(int num: vals){
        if(vals.find(num-1) == vals.end()){
            int j=0, count=0;
            while(vals.find(num+j) != vals.end()){
                count++;
                j++;
            }
            result = max(result, count);
        }
    }
    return result;

}

int main() {
    // vector<int> nums{100, 4, 200, 1, 3, 2};
    // vector<int> nums{0, -1};
    vector<int> nums{1,-8,7,-2,-4,-4,6,3,-4,0,-7,-1,5,1,-9,-3};
    cout << longestConsecutive(nums);
}