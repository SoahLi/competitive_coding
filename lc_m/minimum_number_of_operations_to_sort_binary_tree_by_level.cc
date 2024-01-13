/*
My idea is to use an unordered_map to group values that have the same heights. Then, for each grouping, sort somehow, i'm not sure how i'm going to keep track of the amount of swaps that need to be made but we'll see
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Submission 1: Time limit exceeded
// void assignNodeLevels(TreeNode* root, int level, unordered_map<int, vector<int>>& levels) {
//     if(root == nullptr) return;

//     levels[level].push_back(root->val);
//     assignNodeLevels(root->left, level+1, levels);
//     assignNodeLevels(root->right, level+1, levels);
// }

// int minimumOperations(TreeNode* root) {
//     unordered_map<int, vector<int>> levels;
//     int level = 0;

//     assignNodeLevels(root, level, levels);

//     //selection sort
//     int low=0, comp=0, count=0, temp;
//     for(auto& x : levels) {
//         low = comp = 0;
//         for(int i=0; i<x.second.size(); i++) {
//             low = comp = i;
//             for(int j=i; j<x.second.size(); j++) {
//                 if(x.second[j] < x.second[low]) low = j;
//             }
//             if(comp != low) {
//                 count++;
//                 temp = x.second[i];
//                 x.second[i] = x.second[low];
//                 x.second[low] = temp; 
//             }
//         }

//     }

//     return count;
// }

void assignNodeLevels(TreeNode* root, int level, unordered_map<int, vector<int>>& levels) {
    if(root == nullptr) return;

    levels[level].push_back(root->val);
    assignNodeLevels(root->left, level+1, levels);
    assignNodeLevels(root->right, level+1, levels);
}

int countSwaps(vector<int> nums){
    vector<pair<int, int>> v;
    int n = nums.size(), count=0;

    for(int i=0; i<n; i++) {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        if(v[i].second == i) continue;
        else {
            count++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }

    return count;
}

int minimumOperations(TreeNode* root) {
    unordered_map<int, vector<int>> levels;
    int level = 0;

    assignNodeLevels(root, level, levels);

    //selection sort
    int count=0;
    for(auto& x : levels) {
        count += countSwaps(x.second);
    }

    return count;
}

int main() {
    // TreeNode* myTreeNode = new TreeNode(1, new TreeNode(4, new TreeNode(7), new TreeNode(6)), new TreeNode(3, new TreeNode(8, new TreeNode(9), nullptr), new TreeNode(5, new TreeNode(10), nullptr)));
    TreeNode* myTreeNode = new TreeNode(1, new TreeNode(3, new TreeNode(7), new TreeNode(6)), new TreeNode(2, new TreeNode(5), new TreeNode(4)));
    // TreeNode* myTreeNode = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));
    cout << minimumOperations(myTreeNode);

}