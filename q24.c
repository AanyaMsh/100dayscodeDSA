// Delete First Occurrence of a Key
// Problem: Delete First Occurrence of a Key - Implement using a linked list with dynamic memory allocation.
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

struct Node* deleteKey(struct Node* head, int key) {

    // Case 1: delete head
    if (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key found
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" ");
        head = head->next;
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

    int n, value, key;
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
            tail = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    freeList(head);

    return 0;
}
