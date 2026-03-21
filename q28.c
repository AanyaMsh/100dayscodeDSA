// Circular Linked List Creation and Traversal
// Problem: Circular Linked List Creation and Traversal - Implement using a linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printCircular(struct Node* head, int n) {
    if (head == NULL) return;

    struct Node* temp = head;

    for (int i = 0; i < n; i++) {
        printf("%d", temp->data);
        if (i < n - 1) printf(" ");
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    int n, value;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL)
        tail->next = head;

    printCircular(head, n);

    return 0;
}
