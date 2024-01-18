#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix(nums.size(), 1), suffix(nums.size(), 1), result(nums.size());
    int n = nums.size();


    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for(int i=nums.size()-2; i>=0; i--) {
        suffix[i] = suffix[i+1] * nums[i+1];
    }


    for(int i=0; i<n; i++) {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
} 

int main(){
    // vector<int> input{1, 2, 3, 4};
    vector<int> input{-1,1,0,-3,3};
    input = productExceptSelf(input);
    for(int num: input){
        cout << num << " ";
    }
}