// Doubly Linked List Insertion and Traversal
// Problem: Doubly Linked List Insertion and Traversal - Implement using a linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printForward(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
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
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printForward(head);

    freeList(head);

    return 0;
}
