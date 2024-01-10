#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


bool comp(pair<int, int>& a, pair<int, int> b) {
    return a.second > b.second;
}


vector<vector<int>> findMatrix(vector<int>& nums) {
    map<int, int, less<int>> map;
    for(int num : nums) {
        map[num]++;
    }
    vector<pair<int,int>> nodes;

    for(auto& node : map) {
        nodes.push_back(node);    
    }

    sort(nodes.begin(), nodes.end(), comp);

    vector<vector<int>> result;
    for(auto& node : nodes) {
        for(int i=0; i<node.second; i++){
            if(i >= result.size())
                result.push_back(vector<int>{node.first});
            else
                result[i].push_back(node.first);
        }
    }

    return result;


}

int main() {
    // vector<int> nums{1,3,4,1,2,3,1};
    vector<int> nums{1,2,3,4};
    vector<vector<int>> result = findMatrix(nums);
    for(vector<int> arr : result) {
        for(int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}