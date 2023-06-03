#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

void deleteRoot(struct node* head) {
    if (head == NULL) {
        printf("Heap is empty.\n");
        return;
    }
    

    struct node* temp = head;

    head = (head)->next;

    free(temp);
}

void heapify(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct node* curr = head;
    struct node* parent = NULL;

    while (curr != NULL) {
        parent = curr;
        struct node* child = curr->next;

        while (child != NULL) {
            if (parent->data > child->data) {
                int temp = parent->data;
                parent->data = child->data;
                child->data = temp;
            }
            child = child->next;
        }
        curr = curr->next;
    }
}

void printHeap(struct Node* head) {
    if (head == NULL) {
        printf("Heap is empty.\n");
        return;
    }

    struct node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {

    insert(head, 5);
    insert(head, 8);
    insert(head, 3);
    insert(head, 10);

    printf("Initial heap: ");
    printHeap(head);

    // Delete the root node
    deleteRoot(head);

    printf("Heap after deleting root: ");
    printHeap(head);

    // Heapify the heap
    heapify(head);

    printf("Heap after heapify: ");
    printHeap(head);

    return 0;
}