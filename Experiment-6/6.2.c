#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* inorderSuccessor(
    struct TreeNode* root,
    struct TreeNode* p
) {
    struct TreeNode* successor = NULL;

    while (root != NULL) {
        if (p->val < root->val) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    /*
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */

    struct TreeNode* root = createNode(5);

    root->left = createNode(3);
    root->right = createNode(6);

    root->left->left = createNode(2);
    root->left->right = createNode(4);

    root->left->left->left = createNode(1);

    // Find the inorder successor of node 3.
    struct TreeNode* p = root->left;

    struct TreeNode* result = inorderSuccessor(root, p);

    if (result != NULL) {
        printf(
            "Inorder Successor of %d: %d\n",
            p->val,
            result->val
        );
    } else {
        printf(
            "Inorder Successor of %d: Does not exist\n",
            p->val
        );
    }

    freeTree(root);

    return 0;
}
