#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Submission 1: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n + m)
*/
// vector<TreeNode*> getChildren(const vector<TreeNode*> nodes,vector<int>& nodeValues){
//     vector<TreeNode*> result;
//     for(TreeNode* node: nodes){
//         if(node->left != nullptr) {
//             result.push_back(node->left);
//             nodeValues.push_back(node->left->val);
//         }
//         if(node->right != nullptr) {
//             result.push_back(node->right);
//             nodeValues.push_back(node->right->val);
//         }
//     }
//     return result;
// }

// vector<vector<int> > levelOrder(TreeNode* root) {
//     //start at root
//     //get all root nodes
//     //group in list
//     //go through list and repeat(not recursively)
//     if(root == nullptr) return vector<vector<int> >();
//     vector<vector<int> > result;
//     vector<TreeNode*> nodes = {root};
//     vector<int> nodeValues = {root->val};
//     while(!(nodes.empty())){
//         result.push_back(nodeValues);
//         nodeValues = {};
//         vector<TreeNode*> nodeChildren = getChildren(nodes, nodeValues);
//         nodes = nodeChildren;
//     }
//     return result;
// }


//Submission 2: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n + m)
*/
// vector<vector<int> > levelOrder(TreeNode* root) {
//     //start at root
//     //get all root nodes
//     //group in list
//     //go through list and repeat(not recursively)
//     if(root == nullptr) return vector<vector<int> >();

//     vector<vector<int> > result;
//     queue<TreeNode*> nodes;
//     nodes.push(root);
//     result.push_back(vector<int>{root->val});
//     vector<int> nodeValues;
//     while(!(nodes.empty())){
//         int size = nodes.size();
//         for(int i=0; i<size; i++){
//             TreeNode* current = nodes.front();
//             if(current->left != nullptr) {
//                 nodeValues.push_back(current->left->val);
//                 nodes.push(current->left);
//             }
//             if(current->right != nullptr) {
//                 nodeValues.push_back(current->right->val);
//                 nodes.push(current->right);
//             }
//             nodes.pop();
//         }
//         if(nodeValues.size() > 0) result.push_back(nodeValues);
//         nodeValues = {};
//     }
//     return result;
// }





//Submission 3: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n + m)
*/
vector<vector<int> > levelOrder(TreeNode* root) {
    //start at root
    //get all root nodes
    //group in list
    //go through list and repeat(not recursively)
    if(root == nullptr) return vector<vector<int> >();

    vector<vector<int> > result;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while(!(nodes.empty())){
        vector<int> nodeValues;
        int size = nodes.size();
        for(int i=0; i<size; i++){
            TreeNode* current = nodes.front();
            nodeValues.push_back(current->val);
            if(current->left != nullptr) {
                nodes.push(current->left);
            }
            if(current->right != nullptr) {
                nodes.push(current->right);
            }
            nodes.pop();
        }
        if(nodeValues.size() > 0) result.push_back(nodeValues);
    }
    return result;
}

int main(){
    // TreeNode* myTreeNode = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // vector<vector<int> > result = levelOrder(myTreeNode);

    // TreeNode* myTreeNode = new TreeNode(1);
    // vector<vector<int> > result = levelOrder(myTreeNode);

    // TreeNode* myTreeNode = new TreeNode();
    // vector<vector<int> > result = levelOrder(myTreeNode);

    TreeNode* myTreeNode = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    vector<vector<int> > result = levelOrder(myTreeNode);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}