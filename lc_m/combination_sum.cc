#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void helper(vector<int> candidates, int target, vector<vector<int>>& result, vector<int> current) {
    if(target == 0) {
        result.push_back(current);
        return;
    }
    else if(target > 0) {
        for(int i=candidates.size()-1; i>=0; i--) {
            current.push_back(candidates[i]);
            helper(candidates, target-candidates[i], result, current);
            current.pop_back();
            candidates.erase(candidates.begin()+i);
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//loop through array
//recall for each num
//add set to list if current nums sum to target
    vector<vector<int>> result;
    vector<int> current;
    helper(candidates, target, result, current);
    return result;
}



int main(){
    // vector<int> candidates{2, 3, 5};
    // vector<vector<int>> result = combinationSum(candidates, 8);
    // vector<int> candidates{2, 3, 6, 7};
    // vector<vector<int>> result = combinationSum(candidates, 7);
    vector<int> candidates{2};
    vector<vector<int>> result = combinationSum(candidates, 1);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}