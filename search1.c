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
struct node* linearSearch(int key) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key) {
            return ptr;
        }
        ptr = ptr->link;
    }
    return NULL;
}
st

14
    int searchKey;
    printf("Enter a value to search for: ");

    scanf("%d", &searchKey);
    struct node* searchResult = linearSearch(searchKey);
    if (searchResult != NULL) {
        printf("Value %d found at address: %p\n", searchKey, searchResult);
    }
    else {
        printf("Value not found in the list.\n");
    }

    return 0;
}
