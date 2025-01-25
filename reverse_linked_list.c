#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

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

