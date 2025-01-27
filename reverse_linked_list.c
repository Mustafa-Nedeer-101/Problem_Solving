#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* curr = &dummy;
    for (int i = 0; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;  // Pointer to the node before the sublist

    // Step 1: Traverse the list to reach the `left`-th node
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Step 2: Reverse the sublist
    struct ListNode* curr = prev->next;  // The `left`-th node
    struct ListNode* next = NULL;
    struct ListNode* subListTail = curr; // Tail of the sublist to be reversed
    for (int i = left; i <= right; i++) {
        next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }

    // Step 3: Connect the reversed sublist with the rest of the list
    subListTail->next = curr;

    return dummy.next;
}

int main() {
    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createList(arr, sizeof(arr)/sizeof(arr[0]));
    
    printf("Original list: ");
    printList(head);

    // Reverse positions 2-4 (should become 1 -> 4 -> 3 -> 2 -> 5)
    int left = 2, right = 4;
    head = reverseBetween(head, left, right);
    
    printf("After reversing positions %d-%d: ", left, right);
    printList(head);

    // Free memory
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}