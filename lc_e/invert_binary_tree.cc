#include <iostream>
#include <queue>
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

void displayBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<TreeNode*> levelOrderQueue;
    levelOrderQueue.push(root);

    while (!levelOrderQueue.empty()) {
        int levelSize = levelOrderQueue.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = levelOrderQueue.front();
            levelOrderQueue.pop();

            if (currentNode != nullptr) {
                std::cout << currentNode->val << " ";

                levelOrderQueue.push(currentNode->left);
                levelOrderQueue.push(currentNode->right);
            } else {
                std::cout << "null ";
            }
        }

        std::cout << std::endl;
    }
}

//Submission 1: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(1);
*/
TreeNode* invertTree(TreeNode* root) {
    //create vectors for right and left side of root nodes
    //recurse through left tree, and invert any of its children
    if(root == nullptr) return nullptr;

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(){
    TreeNode* myTreeNode = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    TreeNode* inverted = invertTree(myTreeNode);
    displayBinaryTree(inverted);
}