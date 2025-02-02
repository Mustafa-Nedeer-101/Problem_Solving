#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    // Create two dummy nodes to act as the heads of the two partitions
    struct ListNode less_head = {0, NULL};
    struct ListNode greater_head = {0, NULL};
    
    // Pointers to the current end of the two partitions
    struct ListNode *less_ptr = &less_head;
    struct ListNode *greater_ptr = &greater_head;
    
    // Traverse the original list
    while (head != NULL) {
        if (head->val < x) {
            // Append to the less partition
            less_ptr->next = head;
            less_ptr = less_ptr->next;
        } else {
            // Append to the greater partition
            greater_ptr->next = head;
            greater_ptr = greater_ptr->next;
        }
        head = head->next;
    }
    
    // Terminate the greater partition
    greater_ptr->next = NULL;
    
    // Merge the two partitions
    less_ptr->next = greater_head.next;
    
    // Return the head of the merged list
    return less_head.next;
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the partition function
int main() {
    // Example usage
    struct ListNode* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(2);
    
    int x = 3;
    printf("Original list: ");
    printList(head);
    
    struct ListNode* result = partition(head, x);
    
    printf("Partitioned list: ");
    printList(result);
    
    return 0;
}