void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    head = head->link;
    free(temp);
    printf("First node deleted.\n");
}

void deleteAtMiddle(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* prev = NULL;
    struct node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                head = current->link;
            } else {
                prev->link = current->link;
            }
            free(current);
            printf("Node with value %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->link;
    }

    printf("Node with value %d not found.\n", key);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->link == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct node* prev = NULL;
    struct node* current = head;

    while (current->link != NULL) {
        prev = current;
        current = current->link;
    }

    prev->link = NULL;
    free(current);
    printf("Last node deleted.\n");
}
