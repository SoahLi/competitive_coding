#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//CODE BEFORE LOOKING AT ANSWER
// void combinationSum(vector<int>& candidates, int target, unordered_map<int, vector<int>> dp, vector<vector<int>>& result, vector<int> current, int sum){
//     if(sum == target) {
//         dp[sum].push_back(current.back());
//         result.push_back(current);
//     }
//     else if((dp.find(sum) != dp.end()) && (dp[sum].size() > 0)){
//         for(int num: dp[sum]){
//             current.push_back(num);
//             combinationSum(candidates, target, dp, result, current, sum);
//             current.pop_back();
//         }
//     }
//     else{
//         for(int num: candidates){
//             current.push_back(num);
//             combinationSum(candidates, target, dp, result, current, sum);
//             current.pop_back();
//         }    
//     }
// }

// vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//     vector<vector<int>> result;
//     unordered_map<int, vector<int>> dp;
//     vector<int> current;
//     int sum = 0;
//     combinationSum(candidates, target, dp, result, current, sum);
//     return result;
// }

void combinationSum(vector<int> candidates, int sum, vector<int> current, vector<vector<int>> result){
    if(sum == 0){
        result.push_back(current)
    }
    else if()
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    int sum = target;
    combinationSum(candidates, target result, current, sum);
    return result;
}



int main(){
    vector<int> candidates{2, 3, 5};
    vector<vector<int>> result = combinationSum(candidates, 8);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}