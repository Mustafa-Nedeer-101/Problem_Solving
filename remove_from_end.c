#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
struct ListNode {
    int val;
    struct ListNode *next;
};

// Solution: Remove nth node from end using two pointers
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *fast = &dummy, *slow = &dummy;

    // Create n-node gap between fast and slow
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // Move pointers until fast reaches last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Skip the target node
    slow->next = slow->next->next;
    
    return dummy.next;
}

// Helper: Create linked list from array
struct ListNode* createList(int* arr, int size) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *curr = &dummy;
    
    for (int i = 0; i < size; i++) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    return dummy.next;
}

// Helper: Print linked list
void printList(struct ListNode* head) {
    struct ListNode *curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

// Test cases
int main() {
    // Test Case 1: Remove 2nd node from end (4)
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode *head1 = createList(arr1, 5);
    
    printf("Original list 1: ");
    printList(head1);
    
    head1 = removeNthFromEnd(head1, 2);
    printf("After removing 2nd from end: ");
    printList(head1);  // Expected: 1 2 3 5

    // Test Case 2: Remove head node (n = list length)
    int arr2[] = {10, 20, 30};
    struct ListNode *head2 = createList(arr2, 3);
    
    printf("\nOriginal list 2: ");
    printList(head2);
    
    head2 = removeNthFromEnd(head2, 3);
    printf("After removing 3rd from end: ");
    printList(head2);  // Expected: 20 30

    // Free memory
    struct ListNode *temp;
    while (head1) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}