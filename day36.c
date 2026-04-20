#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // maintain circular link
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) return;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circular link
        free(temp);
    }
}

// Display queue
void display() {
    if (front == NULL) return;

    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    // Input n elements
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Input m dequeue operations
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Output result
    display();

    return 0;
}
