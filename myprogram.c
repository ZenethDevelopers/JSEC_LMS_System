#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeLinkedList(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 7);
    head = insertAtBeginning(head, 9);

    // Display the linked list
    displayList(head);

    // Free the memory occupied by the linked list
    freeLinkedList(head);

    return 0;
}
