# binary-tree-playground


There are three **depth-first traversal methods** (Pre-order, In-order, Post-order) and **breadth-first traversal (BFS)** implemented in **C**.

We'll also include a basic binary tree setup to make the examples complete.

---

### **1. Binary Tree Structure in C**

```c
#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

---

### **2. Pre-order Traversal (DFS: Node → Left → Right)**

#### **Recursive Implementation**

```c
void preOrder(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->val); // Visit the node
    preOrder(root->left);     // Traverse the left subtree
    preOrder(root->right);    // Traverse the right subtree
}
```

#### **Iterative Implementation**

```c
#include <stdbool.h>
#include <limits.h> // For stack implementation

#define STACK_MAX 100

typedef struct {
    Node* data[STACK_MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool push(Stack* stack, Node* node) {
    if (stack->top >= STACK_MAX - 1) return false;
    stack->data[++stack->top] = node;
    return true;
}

Node* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->data[stack->top--];
}

void preOrderIterative(Node* root) {
    if (root == NULL) return;

    Stack stack;
    initStack(&stack);
    push(&stack, root);

    while (!isEmpty(&stack)) {
        Node* current = pop(&stack);
        printf("%d ", current->val);

        if (current->right != NULL) push(&stack, current->right);
        if (current->left != NULL) push(&stack, current->left);
    }
}
```

---

### **3. In-order Traversal (DFS: Left → Node → Right)**

#### **Recursive Implementation**

```c
void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);      // Traverse the left subtree
    printf("%d ", root->val); // Visit the node
    inOrder(root->right);     // Traverse the right subtree
}
```

#### **Iterative Implementation**

```c
void inOrderIterative(Node* root) {
    Stack stack;
    initStack(&stack);
    Node* current = root;

    while (!isEmpty(&stack) || current != NULL) {
        if (current != NULL) {
            push(&stack, current);
            current = current->left;
        } else {
            current = pop(&stack);
            printf("%d ", current->val); // Visit the node
            current = current->right;
        }
    }
}
```

---

### **4. Post-order Traversal (DFS: Left → Right → Node)**

#### **Recursive Implementation**

```c
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);    // Traverse the left subtree
    postOrder(root->right);   // Traverse the right subtree
    printf("%d ", root->val); // Visit the node
}
```

#### **Iterative Implementation**

```c
void postOrderIterative(Node* root) {
    if (root == NULL) return;

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    push(&stack1, root);
    while (!isEmpty(&stack1)) {
        Node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) push(&stack1, current->left);
        if (current->right != NULL) push(&stack1, current->right);
    }

    while (!isEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->val); // Visit the node
    }
}
```

---

### **5. Breadth-First Search (BFS / Level Order Traversal)**

#### **Iterative Implementation Using a Queue**

```c
#include <stddef.h>

typedef struct Queue {
    Node* data[STACK_MAX];
    int front, rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = -1;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

bool enqueue(Queue* queue, Node* node) {
    if (queue->rear == STACK_MAX - 1) return false;
    if (queue->front == -1) queue->front = 0;
    queue->data[++queue->rear] = node;
    return true;
}

Node* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    Node* node = queue->data[queue->front];
    if (queue->front >= queue->rear) queue->front = queue->rear = -1;
    else queue->front++;
    return node;
}

void bfs(Node* root) {
    if (root == NULL) return;

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);

    while (!isQueueEmpty(&queue)) {
        Node* current = dequeue(&queue);
        printf("%d ", current->val); // Visit the node

        if (current->left != NULL) enqueue(&queue, current->left);
        if (current->right != NULL) enqueue(&queue, current->right);
    }
}
```

---

### **6. Example Binary Tree**

```c
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Pre-order: ");
    preOrder(root);
    printf("\n");

    printf("In-order: ");
    inOrder(root);
    printf("\n");

    printf("Post-order: ");
    postOrder(root);
    printf("\n");

    printf("BFS: ");
    bfs(root);
    printf("\n");

    return 0;
}
```

---

### **Outputs for This Tree**

```
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

- **Pre-order**: `1 2 4 5 3 6 7`
- **In-order**: `4 2 5 1 6 3 7`
- **Post-order**: `4 5 2 6 7 3 1`
- **BFS**: `1 2 3 4 5 6 7`

---

That's everything you need to try all traversals on your own!
