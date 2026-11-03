#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value)
        : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        while (root != nullptr) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return successor;
    }
};

int main() {
    /*
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    // Find the inorder successor of node 3.
    TreeNode* p = root->left;

    Solution solution;
    TreeNode* result = solution.inorderSuccessor(root, p);

    if (result != nullptr) {
        cout << "Inorder Successor of " << p->val
             << ": " << result->val << '\n';
    } else {
        cout << "Inorder Successor of " << p->val
             << ": Does not exist\n";
    }

    // Free allocated memory.
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
