#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "queue_tree_node.h"
#include "helper.h"


struct ListNode {
    int val;
    struct ListNode *next;
};


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // Define hash tables for rows, columns, and boxes
    HashTable* rows[9];
    HashTable* cols[9];
    HashTable* boxes[9];
    
    // Initialize hash tables
    for (int i = 0; i < 9; i++) {
        rows[i] = createHashTable(9);
        cols[i] = createHashTable(9);
        boxes[i] = createHashTable(9);
    }
    
    // Iterate over each cell in the board
    for (int i = 0; i < boardSize; i++) { // Every Row
        for (int j = 0; j < *boardColSize; j++) { // Every Cell
            char num = board[i][j];
            if (num != '.') {
                int n = num - '0';
                int boxIndex = (i / 3) * 3 + j / 3;
                
                // Check if the number is already in the current row, column, or box
                if (search(rows[i], n) == n || search(cols[j], n) == n || search(boxes[boxIndex], n) == n) {
                    return false;
                }
                
                // Insert the number into the current row, column, and box
                insert(rows[i], n);
                insert(cols[j], n);
                insert(boxes[boxIndex], n);
            }
        }
    }
    
    // Free hash tables
    for (int i = 0; i < 9; i++) {
        freeHashTable(rows[i]);
        freeHashTable(cols[i]);
        freeHashTable(boxes[i]);
    }
    
    return true;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  // Empty Tree
  if (root == NULL) {
    (*returnSize) = 0;
    return NULL;
  }
  // Variables
  int** arrayOfArrays = malloc(sizeof(int*) * 2000);
  int* columnSizes = malloc(sizeof(int) * 2000);
  int index = 0;
  int columnIndex = 0; // Has to Be Reset
  int levelIndicator = 1; // Initial Value Is 1
  queue* q = makeQueue();
  enqueue(q, root);

  // While The Next Level Is Not Empty
  while (levelIndicator > 0) {
    int nextNumOfChildren = 0;
    int* ithArray = malloc(sizeof(int) * levelIndicator);
    columnIndex = 0;
    arrayOfArrays[index] = ithArray;
    columnSizes[index] = levelIndicator;
    index++;

    // dequeue all nodes for that level
    for (int i = 0; i < levelIndicator; i++) {
      struct TreeNode* n = dequeue(q);
      if (n -> left != NULL) {
        nextNumOfChildren++;
        enqueue(q, n->left);
      }
      if (n -> right != NULL) {
        nextNumOfChildren++;
        enqueue(q, n->right);
      }

      ithArray[columnIndex] = n->val;
      columnIndex++;
    }

    levelIndicator = nextNumOfChildren;
  }

  (*returnSize) = index;
  (*returnColumnSizes) = columnSizes;
  return arrayOfArrays;
}
// Main For Test
int main(void) {

  struct TreeNode* one = malloc(sizeof(struct TreeNode));
  struct TreeNode* two = malloc(sizeof(struct TreeNode));
  struct TreeNode* three = malloc(sizeof(struct TreeNode));

  one->val = 1;
  one->left = two;
  return 0;
}
