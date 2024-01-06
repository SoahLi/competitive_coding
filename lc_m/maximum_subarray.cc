#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int best=nums[0], sum=0;
    for(int i=0; i<nums.size(); i++) {
        sum = max(sum+nums[i], nums[i]);
        best = max(best, sum);
    }
    return best;
}

int main() {
    // vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    // cout << maxSubArray(nums) << '\n';

    // vector<int> nums{1};
    // cout << maxSubArray(nums) << '\n';

    // vector<int> nums{5,4,-1,7,8};
    // cout << maxSubArray(nums) << '\n';


    vector<int> nums{-1};
    cout << maxSubArray(nums) << '\n';
}