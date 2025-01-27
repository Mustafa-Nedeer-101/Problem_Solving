#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Create a dummy node to handle edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy; // Points to the last unique node
    struct ListNode* curr = head;  // Current node being processed

    while (curr != NULL) {
        // Check if the current node has duplicates
        if (curr->next != NULL && curr->val == curr->next->val) {
            int duplicateVal = curr->val; // Store the duplicate value
            // Skip all nodes with the duplicate value
            while (curr != NULL && curr->val == duplicateVal) {
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp); // Free the duplicate node
            }
            prev->next = curr; // Link the previous node to the next unique node
        } else {
            // No duplicates, move prev and curr forward
            prev = curr;
            curr = curr->next;
        }
    }

    struct ListNode* result = dummy->next; // Result starts from dummy->next
    free(dummy); // Free the dummy node
    return result;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function for testing
int main() {
    // Example: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    struct ListNode* result = deleteDuplicates(head);

    printf("Modified List: ");
    printList(result);

    return 0;
}
