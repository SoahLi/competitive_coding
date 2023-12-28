#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool compare(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr && subRoot == nullptr){
        return true;
    }
    else if(root == nullptr || subRoot == nullptr) {
        return false;
    }
    else if(root->val != subRoot->val) {
        return false;
    }    
    else {
        return compare(root->left, subRoot->left) && compare(root->right, subRoot->right);
    }
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(subRoot == nullptr){
        return true;
    }
    else if(root == nullptr)
        return false;
    else if(compare(root, subRoot)){
        return true;
    }
    else 
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}


int main() {
    // TreeNode* myTreeNode = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    // TreeNode* compare = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    // cout << isSubtree(myTreeNode, compare);

    TreeNode* myTreeNode = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
    TreeNode* compare = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    cout << isSubtree(myTreeNode, compare);

}