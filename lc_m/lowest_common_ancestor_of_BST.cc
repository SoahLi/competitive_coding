#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Submission 1: PASSING
/*
 * Time Complexity:
 * Space Complexity:
 * Completed in: 35 minutes
*/
vector<TreeNode*> getBranchPath(TreeNode* root, int target) {
    vector<TreeNode*> visited;
    TreeNode* cursor = root;
    while(cursor != nullptr){
        visited.push_back(cursor);
        if(cursor->val == target) 
            break;
        else if(target > cursor->val)
            cursor = cursor->right;
        else
            cursor = cursor->left;
    }
    return visited;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //find the first node, add all visited nodes to vector
    //find the second node, add all visited nodes to another vector
    //loop through length of larger vector
        //when the values of the vector stop equalling eachother, return the LCA
    vector<TreeNode*> pPath = getBranchPath(root, p->val);
    vector<TreeNode*> qPath = getBranchPath(root, q->val);
    int i=0;
    while (i < pPath.size() && i < qPath.size() && pPath[i]->val == qPath[i]->val)
        i++;

    // Check if i is within the bounds of both vectors
    if (i > 0 && i <= pPath.size())
        return pPath[i - 1];
    else
        return nullptr; 
}

int main() {
    // TreeNode* myTreeNode = new TreeNode(6);
    // myTreeNode->left = new TreeNode(2);
    // myTreeNode->right = new TreeNode(8);
    // myTreeNode->left->left = new TreeNode(0);
    // myTreeNode->left->right = new TreeNode(4);
    // myTreeNode->right->left = new TreeNode(7);
    // myTreeNode->right->right = new TreeNode(9);
    // myTreeNode->left->right->left = new TreeNode(3);
    // myTreeNode->left->right->right = new TreeNode(5);
    // cout << (lowestCommonAncestor(myTreeNode, myTreeNode->left, myTreeNode->right))->val;
    TreeNode *myTreeNode = new TreeNode(6);
    myTreeNode->left = new TreeNode(2);
    myTreeNode->right = new TreeNode(8);
    myTreeNode->left->left = new TreeNode(0);
    myTreeNode->left->right = new TreeNode(4);
    myTreeNode->right->left = new TreeNode(7);
    myTreeNode->right->right = new TreeNode(9);
    myTreeNode->left->right->left = new TreeNode(3);
    myTreeNode->left->right->right = new TreeNode(5);
    cout << lowestCommonAncestor(myTreeNode, new TreeNode(2), new TreeNode(4))->val;
}