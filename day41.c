#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (choice == 2) {
            dequeue();
        }
    }

    return 0;
}
