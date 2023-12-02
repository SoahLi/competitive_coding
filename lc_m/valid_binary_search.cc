#include <iostream>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// //Submission 1 FAILED:[5,4,6,null,null,3,7], returned true, exprected false
// bool isValidBST(TreeNode* root){
//     if(root->left == nullptr && root->right == nullptr) return true;
//     else if(root->left == nullptr){
//         if(root->right->val > root->val) return isValidBST(root->right);
//     }
//     else if(root->right == nullptr){
//         if(root->left->val < root->val) return isValidBST(root->left);
//     }
//     else{
//         if(root->left->val < root->val && root->right->val > root->val){
//             return isValidBST(root->left) && isValidBST(root->right);
//         }
//     }
//     // return false;
// }

// int main(){
//     //[5,4,6,null,null,3,7]
//     // TreeNode* root = new TreeNode(3, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(4 ,new TreeNode(1), new TreeNode(5)));
//     // TreeNode* root = new TreeNode(5, new TreeNode(4, NULL, NULL), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
//     // TreeNode* root = new TreeNode(5, new TreeNode(1, NULL, NULL), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
//     cout << isValidBST(root);
// }
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root, int min, int max){

}

bool isValidBST(TreeNode* root){
    if(root->left == nullptr && root->right == nullptr) return true;
    else if(root->left == nullptr){
        if(root->right->val > root->val) return isValidBST(root->right);
    }
    else if(root->right == nullptr){
        if(root->left->val < root->val) return isValidBST(root->left);
    }
    else{
        if(root->left->val < root->val && root->right->val > root->val){
            return isValidBST(root->left) && isValidBST(root->right);
        }
    }
    int min = INT_MIN, max = INT_MAX;
    return isValidBST()
    // return false;
}

int main(){
    //[5,4,6,null,null,3,7]
    // TreeNode* root = new TreeNode(3, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(4 ,new TreeNode(1), new TreeNode(5)));
    // TreeNode* root = new TreeNode(5, new TreeNode(4, NULL, NULL), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
    // TreeNode* root = new TreeNode(5, new TreeNode(1, NULL, NULL), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    cout << isValidBST(root);
}