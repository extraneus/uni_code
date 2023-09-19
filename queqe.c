#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_QUEUE_SIZE - 1);
}

// Function to add an element to the rear of the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1) {
        front = 0; // Initialize front when adding the first element
    }

    rear++;
    queue[rear] = value;
}

// Function to remove an element from the front of the queue
int dequeue() {
    int value;

    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    value = queue[front];

    if (front == rear) {
        // Queue has only one element, so reset front and rear
        front = -1;
        rear = -1;
    } else {
        // Move the front index to the next element
        front++;
    }

    return value;
}

int main() {
    // Enqueue some elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Dequeue and print elements
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}
