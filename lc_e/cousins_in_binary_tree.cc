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

void findNodePath(TreeNode* root, int target, vector<int> currentPath, vector<int>& truePath) {
    if(root == nullptr) return;

    currentPath.push_back(root->val);

    if(root -> val == target) {
        truePath = currentPath;
        return;
    }

    findNodePath(root->left, target, currentPath, truePath);
    findNodePath(root->right, target, currentPath, truePath);
}

bool isCousins(TreeNode* root, int x, int y) {
    vector<int> p, xPath, yPath;
    findNodePath(root, x, p, xPath);
    findNodePath(root, y, p, yPath);

    if(xPath.size() != yPath.size()) return false;
    if(xPath.size() < 2) return false;
    int n = xPath.size();
    for(int i=0; i<n; i++) {
        cout << xPath[i] << " " << yPath[i] << '\n';
    }

    if(xPath[n-3] == yPath[n-3])
        return true;
    else
        return false;
}

int main() {
    TreeNode* myTreeNode = new TreeNode()

}