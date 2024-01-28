#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// int subarraySum(vector<int>& nums, int k) {
//     int n = nums.size();

//     vector<int> pre(nums.size());
//     pre[0] = nums[0];

//     for(int i=1; i<n; i++) {
//         pre[i] = nums[i] + pre[i-1];
//     }

//     // unordered_map<int, int> seen;
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++) {
//             if((pre[j] - pre[i]+nums[i]) == k) {
//                 ans++;
//             }
//         }
//     }

//     return ans;
// }

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> pre(nums.size());
    pre[0] = nums[0];

    for(int i=1; i<n; i++) {
        pre[i] = nums[i] + pre[i-1];
    }

    unordered_map<int, int> seen;
    seen[0]++;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        if(seen.find(pre[i] - k) != seen.end()) {
            ans += seen[pre[i] - k];
        }
        seen[pre[i]]++;
    }

    return ans;
}



int main() {
    vector<int> nums{1, 1, 1};
    cout << subarraySum(nums, 2);
    // vector<int> nums{1, 2, 3, 4, 5};
    // cout << subarraySum(nums, 9);
    // vector<int> nums{1, 2, 3};
    // cout << subarraySum(nums, 3);
}