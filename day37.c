#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down (for delete)
void heapifyDown(int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Insert operation
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Delete operation
void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]); // print deleted element

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Peek operation
void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// Main
int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            deleteMin();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
