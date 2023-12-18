#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Submission 1: Wrong Answer
// void kthSmallest(TreeNode* root, int& k, int& result){
//     if(root -> left != nullptr) kthSmallest(root -> left, k, result);
//     if(k == 1) {
//         result = root->val;
//     }
//     k--;
//     if(root -> right != nullptr && k > 1) kthSmallest(root -> right, k, result);
// }

// int kthSmallest(TreeNode* root, int k) {
//     //find the left side of the tree, this is the smallest element
//     //iterate k times doing an inorder search
//     //return the element you land on
//     int result = root->val;
//     kthSmallest(root, k, result);
//     return result;
// }

//Submission 2: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Completed in: Passed time limit
*/
void kthSmallest(TreeNode* root, int& k, int& count, int& result){
    if(root -> left != nullptr) kthSmallest(root -> left, k, count, result);
    count++;
    if(k == count) {
        result = root->val;
    }
    if(root -> right != nullptr && k > 1) kthSmallest(root -> right, k, count, result);
}

int kthSmallest(TreeNode* root, int k) {
    //find the left side of the tree, this is the smallest element
    //iterate k times doing an inorder search
    //return the element you land on
    int result = root->val;
    int count = 0;
    kthSmallest(root, k, count, result);
    return result;
}

int main() {
    // TreeNode* myTreeNode = new TreeNode(10, new TreeNode(8, new TreeNode(6, new TreeNode(5), new TreeNode(7)), new TreeNode(9)), new TreeNode(12, new TreeNode(11), new TreeNode(15)));
    // cout << kthSmallest(myTreeNode, 9);
    // TreeNode* myTreeNode = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    // cout << kthSmallest(myTreeNode, 1);
    // TreeNode* myTreeNode = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6));
    // cout << kthSmallest(myTreeNode, 3);
    TreeNode* myTreeNode = new TreeNode(1, nullptr, new TreeNode(2));
    cout << kthSmallest(myTreeNode, 2);
}