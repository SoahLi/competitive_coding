#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
//Recursive solution
// bool isSymmetric(TreeNode *left, TreeNode *right) {
//   if (left == nullptr || right == nullptr) {
//     if (left == nullptr && right == nullptr)
//       return true;
//     else
//       return false;
//   }

//   if (left->val != right->val)
//     return false;
//   else
//     return (isSymmetric(left->left, right->right) &&
//             isSymmetric(left->right, right->left));
// }

// bool isSymmetric(TreeNode *root) {
//   TreeNode *left = root->left;
//   TreeNode *right = root->right;
//   return isSymmetric(left, right);
// }


bool isSymmetric(TreeNode *left, TreeNode *right) {
  if (left == nullptr || right == nullptr) {
    if (left == nullptr && right == nullptr)
      return true;
    else
      return false;
  }

  if (left->val != right->val)
    return false;
  else
    return (isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left));
}

// bool isSymmetric(TreeNode *root) {
//   TreeNode *left = root->left;
//   TreeNode *right = root->right;
//   return isSymmetric(left, right);
// }

bool isSymmetric(TreeNode *root) {
  
}

int main() {
  TreeNode *myTreeNode =
      new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                   new TreeNode(2, new TreeNode(4), new TreeNode(3)));
  cout << isSymmetric(myTreeNode);
}
