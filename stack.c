#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct StackNode {
  struct Node *treeNode;  // The tree node that the stack will hold
  struct StackNode *next; // Pointer to the next stack node
} StackNode;

// Function to create a new stack node
StackNode *create_stack_node(struct Node *treeNode) {
  StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
  new_node->treeNode = treeNode;
  new_node->next = NULL;
  return new_node;
}

// Push an element onto the stack
void push(StackNode **top, struct Node *treeNode) {
  StackNode *new_node = create_stack_node(treeNode);
  new_node->next = *top;
  *top = new_node;
}

// Pop an element from the stack
struct Node *pop(StackNode **top) {
  if (*top == NULL)
    return NULL;
  StackNode *temp = *top;
  *top = (*top)->next;
  struct Node *popped_node = temp->treeNode;
  free(temp);
  return popped_node;
}

// Peek at the top element of the stack
struct Node *peek(StackNode *top) {
  return (top == NULL) ? NULL : top->treeNode;
}

// Check if the stack is empty
int is_empty(StackNode *top) { return (top == NULL); }

// Free the stack
void free_stack(StackNode *top) {
  while (top != NULL) {
    StackNode *temp = top;
    top = top->next;
    free(temp);
  }
}
