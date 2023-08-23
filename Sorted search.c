#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} * head;

// ... (other functions)

struct node* searchSorted(int item) {
    struct node* ptr = head;
    struct node* location = NULL;

    while (ptr != NULL) {
        if (item < ptr->data) {
            ptr = ptr->link;
        } else if (item == ptr->data) {
            location = ptr;
            break;
        } else {
            location = NULL;
            break;
        }
    }

    return location;
}

int main() {
    // ... (other parts of main)

    int searchItem;
    printf("Enter the item to search: ");
    scanf("%d", &searchItem);

    struct node* result = searchSorted(searchItem);
    if (result) {
        printf("Item %d found.\n", searchItem);
    } else {
        printf("Item %d not found.\n", searchItem);
    }

    return 0;
}
