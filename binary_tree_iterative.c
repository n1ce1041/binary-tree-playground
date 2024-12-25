#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

// Define the structure for a queue node
typedef struct QueueNode {
  struct Node *tree_node;
  struct QueueNode *next;
} QueueNode;

// Function to create a new queue node
QueueNode *create_queue_node(struct Node *tree_node) {
  QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
  new_node->tree_node = tree_node;
  new_node->next = NULL;
  return new_node;
}

// Function to enqueue a node
void enqueue(QueueNode **front, QueueNode **rear, struct Node *tree_node) {
  QueueNode *new_node = create_queue_node(tree_node);
  if (*rear == NULL) {
    *front = *rear = new_node;
    return;
  }
  (*rear)->next = new_node;
  *rear = new_node;
}

// Function to dequeue a node
struct Node *dequeue(QueueNode **front) {
  if (*front == NULL)
    return NULL;
  QueueNode *temp = *front;
  struct Node *node = temp->tree_node;
  *front = (*front)->next;
  free(temp);
  return node;
}

// Function to check if the queue is empty
int is_queue_empty(QueueNode *front) { return front == NULL; }

// Pre-order Iterative Traversal
void preorder_iterative(struct Node *root) {
  if (root == NULL)
    return;

  StackNode *stack = NULL;
  push(&stack, root);

  while (!is_empty(stack)) {
    struct Node *current = pop(&stack);
    printf("%d ", current->value); // Visit the node

    if (current->right != NULL) {
      push(&stack, current->right);
    }
    if (current->left != NULL) {
      push(&stack, current->left);
    }
  }
}

// In-order Iterative Traversal
void inorder_iterative(struct Node *root) {
  StackNode *stack = NULL;
  struct Node *current = root;

  while (current != NULL || !is_empty(stack)) {
    while (current != NULL) {
      push(&stack, current);
      current = current->left;
    }

    current = pop(&stack);
    printf("%d ", current->value); // Visit the node
    current = current->right;
  }
}

// Post-order Iterative Traversal
void postorder_iterative(struct Node *root) {
  if (root == NULL)
    return;

  StackNode *stack = NULL;
  struct Node *last_visited = NULL;
  struct Node *current = root;

  while (!is_empty(stack) || current != NULL) {
    if (current != NULL) {
      push(&stack, current);
      current = current->left;
    } else {
      struct Node *peek_node = peek(stack);
      if (peek_node->right != NULL && last_visited != peek_node->right) {
        current = peek_node->right;
      } else {
        printf("%d ", peek_node->value); // Visit the node
        last_visited = pop(&stack);
      }
    }
  }
}

// Helper function to create a new tree node
struct Node *create_node(int val) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->value = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Main function for testing
int main() {
  // Creating a simple binary tree for testing
  struct Node *root = create_node(1);
  root->left = create_node(2);
  root->right = create_node(3);
  root->left->left = create_node(4);
  root->left->right = create_node(5);
  root->right->left = create_node(6);
  root->right->right = create_node(7);

  printf("Pre-order Traversal: ");
  preorder_iterative(root);
  printf("\n");

  printf("In-order Traversal: ");
  inorder_iterative(root);
  printf("\n");

  printf("Post-order Traversal: ");
  postorder_iterative(root);
  printf("\n");

  return 0;
}