#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    //find largest num
    //create an array of length largest num that represents the numbers that have been counted
    //go through nums, assigning counted nums 1 with their corresponding index
    //go through array of length nums, return index with value 0


    int largest = 0;
    for(int num : nums)
        largest = max(largest+1, num);
    
    vector<int> seenNumbers(largest+1, 0);
    for(int num : nums)
        seenNumbers[num]++;
    
    for(int i=0; i<seenNumbers.size(); i++) {
        if(seenNumbers[i] == 0)
            return i;
    }
    return largest+1;
}

int main() {
    // vector<int> nums{3, 0, 1};
    // vector<int> nums{9,6,4,2,3,5,7,0,1};
    // vector<int> nums{0};
    // vector<int> nums{1};
    vector<int> nums{0, 1};
    cout << missingNumber(nums);
}