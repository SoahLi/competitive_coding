#include<iostream>
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
 * Space Complexity: O(n)
*/
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
}

int main() {
    // TreeNode* myTreeNode = new TreeNode(3, new TreeNode(9, new TreeNode(6, new TreeNode(8), new TreeNode()), new TreeNode()), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* myTreeNode = new TreeNode(1, new TreeNode(), new TreeNode(2));
    cout << maxDepth(myTreeNode);
}