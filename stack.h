#ifndef STACK_H
#define STACK_H

// Forward declare the Node structure
struct Node;

// Define the structure for the stack node
typedef struct StackNode {
    struct Node *node;  // Use forward-declared Node type
    struct StackNode *next;
} StackNode;

// Function declarations
StackNode* create_stack_node(struct Node *node);
void push(StackNode **top, struct Node *node);
struct Node* pop(StackNode **top);
struct Node* peek(StackNode *top);
int is_empty(StackNode *top);
void free_stack(StackNode *top);

#endif // STACK_H
