#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new node with a given value
Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("Memory allocation error!\n");
    exit(1);
  }
  newNode->value = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Pre-order traversal (DFS): Node → Left → Right
void preOrder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
  }
}

// In-order traversal (DFS): Left → Node → Right
void inOrder(Node *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
  }
}

// Post-order traversal (DFS): Left → Right → Node
void postOrder(Node *root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
  }
}

// Main function to demonstrate tree creation and traversal
int main() {
  // Create the binary tree
  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  // Print tree traversals
  printf("Pre-order traversal: ");
  preOrder(root);
  printf("\n");

  printf("In-order traversal: ");
  inOrder(root);
  printf("\n");

  printf("Post-order traversal: ");
  postOrder(root);
  printf("\n");

  return 0;
}
