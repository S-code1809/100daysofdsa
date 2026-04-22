#include <stdio.h>
#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Get size
int size() {
    if (empty()) return 0;
    return (rear - front + 1);
}

// Push front
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        printf("Overflow\n");
    } else {
        front--;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// Get front
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Get back
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    display();      // 5 10 20

    pop_front();    // 5
    pop_back();     // 20
    display();      // 10

    get_front();    // 10
    get_back();     // 10

    printf("Size: %d\n", size());

    return 0;
}
