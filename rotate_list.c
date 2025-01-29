#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Compute the length of the list
    int length = 1;  // At least 1 node exists
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Optimize k
    k = k % length;
    if (k == 0) return head; // No rotation needed

    // Step 3: Connect the last node to head, making it circular
    tail->next = head;

    // Step 4: Find the new tail (length - k - 1)th node
    struct ListNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head and break the cycle
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Utility function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility function to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    // Example List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL, k = 2
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    printf("Rotated List: ");
    printList(head);

    return 0;
}
