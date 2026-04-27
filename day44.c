#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void push(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* pop(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = newNode(arr[0]);
    push(&q, root);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = pop(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Traversals
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}
