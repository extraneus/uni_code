#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} * head;

void createList(int n) {
    struct node* newnode, * tmp;
    head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the first node: ");
    scanf("%d", &head->data);
    head->link = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Input data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        tmp->link = newnode;
        tmp = tmp->link;
    }
}

void printData() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    }
    else {
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("CURRENT ADDRESS: %p \n DATA: %d \n Next address: %p \n", ptr, ptr->data, ptr->link);
            ptr = ptr->link;
        }
    }
}

void insertAtBeginning(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}

void insertAtMiddle(int position, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    struct node* ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->link = ptr->link;
    ptr->link = newNode;
}

int main() {
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData entered in the list:\n");
    printData();

    int newData;

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newData);
    insertAtBeginning(newData);
    printf("\nData after inserting at the beginning:\n");
    printf("Enter data to insert at the end: ");
    scanf("%d", &newData);
    insertAtEnd(newData);
    printf("\nData after inserting at the end:\n");


    int position;
    printf("Enter position to insert at the middle: ");
    scanf("%d", &position);
    printf("Enter data to insert at position %d: ", position);
    scanf("%d", &newData);
    insertAtMiddle(position, newData);
    printf("\nData after inserting at the middle:\n");
    printData();

    return 0;
}
