#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize stack
void init(struct Stack* stack) {
    stack->top = -1;
}

// Push element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1; // You might want to handle this differently
    }
    return stack->data[stack->top--];
}

// Get the top element of the stack
int top(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; // You might want to handle this differently
    }
    return stack->data[stack->top];
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top >= MAX_SIZE - 1;
}

int main() {
    struct Stack myStack;
    init(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", top(&myStack));

    while (!isEmpty(&myStack)) {
        printf("Popped: %d\n", pop(&myStack));
    }

    return 0;
}
