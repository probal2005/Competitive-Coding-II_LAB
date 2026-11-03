#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Step 1: Find the middle
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;

    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 3: Compare both halves
    struct ListNode* left = head;
    struct ListNode* right = prev;

    while (right != NULL) {
        if (left->val != right->val) {
            return false;
        }

        left = left->next;
        right = right->next;
    }

    return true;
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    // Example: 1 -> 2 -> 2 -> 1
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    printf("Palindrome Linked List: %s\n",
           isPalindrome(head) ? "true" : "false");

    freeList(head);

    return 0;
}
