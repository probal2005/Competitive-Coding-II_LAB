#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    struct TreeNode* p,
    struct TreeNode* q
) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* left =
        lowestCommonAncestor(root->left, p, q);

    struct TreeNode* right =
        lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
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
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    */

    struct TreeNode* root = createNode(3);

    root->left = createNode(5);
    root->right = createNode(1);

    root->left->left = createNode(6);
    root->left->right = createNode(2);

    root->right->left = createNode(0);
    root->right->right = createNode(8);

    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    struct TreeNode* p = root->left;
    struct TreeNode* q = root->left->right->right;

    struct TreeNode* result =
        lowestCommonAncestor(root, p, q);

    if (result != NULL) {
        printf(
            "Lowest Common Ancestor of %d and %d: %d\n",
            p->val,
            q->val,
            result->val
        );
    }

    freeTree(root);

    return 0;
}
