#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
    }
}

// Pop an item from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        int popped = stack[top];
        top--;
        return popped;
    }
}

// Peek at the top item of the stack without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top of the stack: %d\n", peek());

    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
