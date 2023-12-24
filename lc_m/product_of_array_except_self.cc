#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
//use prefix and postfix array
    int n = nums.size();
    vector<int> res(n, 1);
    vector<int> pre(n, 1);
    vector<int> post(n, 1);
    for(int i = 1; i < n; i++) {
        //use nums[i-1] to not include the current num
        pre[i] = pre[i - 1] * nums[i-1];
    }
    for(int i=n-2; i>=0; i--){
        post[i] = post[i+1] * nums[i+1];
    }

    for(int i=0; i<n; i++){
        res[i] = pre[i] * post[i];
    }
    return res;

}

int main(){
    vector<int> input{1, 2, 3, 4};
    input = productExceptSelf(input);
    for(int num: input){
        cout << num << '\n';
    }
}