#include <iostream>
#include <vector>
using namespace std;

//Submission 1: PASSING
/*
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 * Completed in: 30 minutes
*/
// int rob(vector<int>& nums){
//     int best = 0;
//     vector<int> dp = nums;

//     for(int i=nums.size()-1; i>=0; i--){
//         for(int j=i+2; j<nums.size(); j++)
//             dp[i] = max(dp[i], dp[j] + nums[i]);
//         best = max(best, dp[i]);
//     }

//     return best;
// }


//Submission 2: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * Completed in: 45 minutes
*/
int rob(vector<int>& nums){
    int best = 0;
    vector<int> dp = nums;

    for(int i=nums.size()-1; i>=0; i--){
        if(!(i+2 >= nums.size()))
            dp[i] = max(dp[i], dp[i+2] + nums[i]);
        if(!(i+3 >= nums.size()))
            dp[i] = max(dp[i], dp[i+3] + nums[i]);
        best = max(best, dp[i]);
    }

    return best;
}

int main(){
    // vector<int> nums{2, 1, 1, 2};
    // vector<int> nums{1,2,3,1};
    vector<int> nums{2, 7, 9, 3, 1};
    // vector<int> nums{7, 9, 5, 8, 2};
    cout << rob(nums);
}