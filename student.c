#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    float cgpa;
    struct node* link;
} * head;

void createList(int n) {
    struct node* newnode, * tmp;
    head = (struct node*)malloc(sizeof(struct node));
    printf("id for the first node: ");
    scanf("%d", &head->id);
     printf("cgpa for the first node: ");
    scanf("%f", &head->cgpa);
    head->link = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Input id for node %d: ", i);
        scanf("%d", &newnode->id);

         printf("Input cgpa for node %d: ", i);
        scanf("%d", &newnode->cgpa);
        newnode->link = NULL;
        tmp->link = newnode;
        tmp = tmp->link;
    }
}

void printid() {
    if (head == NULL) {
        printf("linked list is empty\n");
    }
    else {
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("CURRENT ADDRESS: %p \n id: %d \n cgpa: %2.f\n Next address: %p \n", ptr, ptr->id,ptr->cgpa, ptr->link);
            ptr = ptr->link;
        }
    }
}

void insertAtBeginning(int id,float cgpa) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->id = id;
    newNode->cgpa=cgpa;
    newNode->link = head;
    head = newNode;
}

void insertAtEnd(int id,int cgpa) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->id = id;
    newNode->cgpa=cgpa;
    newNode->link = NULL;
    struct node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}

void insertAtMiddle(int pos, int id,float cgpa) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->id = id;
    newNode->cgpa=cgpa;

    struct node* ptr = head;
    for (int i = 1; i < pos -1  && ptr != NULL; i++) {
        ptr = ptr->link;
    }

    newNode->link = ptr->link;
    ptr->link = newNode;
}

struct node* search(int key) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->id == key) {
            return ptr;
        }
        ptr = ptr->link;
    }
    return NULL;
}

int main() {
    int n;
    printf("number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\n id entered in the list:\n");
    printid();

    int newid;
    float newcgpa;

    printf("id to insert at the beginning: ");
    scanf("%d", &newid);
    printf("cgpa to insert at the beginning: ");
    scanf("%d", &newcgpa);
    insertAtBeginning(newid,newcgpa);
    printf("id to insert at the end: ");
    scanf("%d", &newid);
     printf("id to insert at the end: ");
    scanf("%d", &newcgpa);
    insertAtEnd(newid,newcgpa);


    int pos;
    printf("position to insert at the middle: ");
    scanf("%d", &pos);
    printf("insert at pos %d and id: ", pos);
    scanf("%d", &newid);
    scanf("%d", &newcgpa);
    insertAtMiddle(pos, newid,newcgpa);
    printf("LINKED LIST: ");
    printid();

    int key;
    printf("key to searc: ");
    scanf("%d", &key);
    struct node* result = search(key);
    if (result != NULL) {
        printf("key%d found at address: %p\n", key, result);
    }
    else {
        printf("NOT FOUND", key);
    }

    return 0;
}
