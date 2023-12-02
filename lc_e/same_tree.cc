#include <iostream>
using namespace std;

//Submission 1: PASSING
/*
 * Time complexity: O(n)
 * Space complexity: O(H) where h is the height of the tree
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;
    else if((p == nullptr || q == nullptr) || (p->val != q->val)) return false;
    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // TreeNode* myTreeNode = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // cout << isSameTree(myTreeNode, myTreeNode);
    
    // TreeNode* treeNode1 = new TreeNode(1,nullptr, new TreeNode(3));
    // TreeNode* treeNode2 = new TreeNode(1, new TreeNode(3), nullptr);
    // cout << isSameTree(treeNode1, treeNode2);

    // TreeNode* treeNode1 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    // TreeNode* treeNode2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    // cout << isSameTree(treeNode1, treeNode2);
    
}