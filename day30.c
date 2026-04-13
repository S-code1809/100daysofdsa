#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create polynomial
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int c, e;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp > 1) {
            printf("%dx^%d", temp->coeff, temp->exp);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%d", temp->coeff);
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
