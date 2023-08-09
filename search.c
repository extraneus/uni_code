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

int searchKey;
    printf("Enter a value to search for: ");
    scanf("%d", &searchKey);
    struct node* searchResult = linearSearch(searchKey);
    if (searchResult != NULL) {
        printf("Value %d found at address: %p\n", searchKey, searchResult);
    }
    else {
        printf("Value %d not found in the list.\n", searchKey);
    }