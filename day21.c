//Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i, value;

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;   // first node
            temp = newNode;
        } else {
            temp->next = newNode;  // link previous node
            temp = newNode;
        }
    }

    return head;
}
void traverseList(struct Node* head) {
    struct Node* temp = head;

    printf("\nLinked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main() {
    int n;
    struct Node* head;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);
    traverseList(head);

    return 0;
}