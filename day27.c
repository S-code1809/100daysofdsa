#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Find intersection (by value)
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;

    while (p1 != NULL) {
        struct Node* p2 = head2;

        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return;
            }
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}
