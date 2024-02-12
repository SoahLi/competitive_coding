#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, int> pre;
unordered_map<int, int> in;
unordered_set<int> seen;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void buildTreeHelper(int prev, int val, TreeNode* root, vector<int>& preorder) {
  cout << val << '\n';
  if(seen.find(val) != seen.end()) return;
  seen.insert(val);
  root = new TreeNode(val);
  buildTreeHelper(val, abs(in[val] - in[prev]), root->right, preorder);
  buildTreeHelper(val, preorder[pre[val]++], root->left, preorder);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  TreeNode* root = new TreeNode(preorder[0]);

  for(int i=0; i<preorder.size(); i++) {
    pre[preorder[i]] = i;
    in[inorder[i]] = i; 
  }

  int prev = in[0], val = pre[0];
  buildTreeHelper(prev, val, root->left, preorder);
  prev = inorder.back();
  buildTreeHelper(prev, val, root->right, preorder);
  return root;
}



void printBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            nodeCount--;
        }
        std::cout << std::endl;
    }
}
int main() {

  buildTree()
}



