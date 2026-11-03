#include <stdio.h>
#include <stdlib.h>

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

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;

    while (even != NULL && even->next != NULL) {
        // Connect odd-positioned nodes
        odd->next = even->next;
        odd = odd->next;

        // Connect even-positioned nodes
        even->next = odd->next;
        even = even->next;
    }

    // Connect odd list with even list
    odd->next = evenHead;

    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);

        if (head->next != NULL) {
            printf(" -> ");
        }

        head = head->next;
    }

    printf("\n");
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(head);

    head = oddEvenList(head);

    printf("Odd Even Linked List: ");
    printList(head);

    freeList(head);

    return 0;
}
