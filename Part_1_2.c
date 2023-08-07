#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
        printf("%d pushed into the stack.\n", val);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from the stack\n", stack[top]);
        top--;
    }
}

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_SIZE - 1);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    // Create an empty stack
    printf("Creation of an empty stack.\n");

    // Push some integer values onto the stack
    push(1);
    push(3);
    push(5);

    // Print the elements of the stack
    printf("Displaying the elements of the stack:\n");
    display();

    // Pop elements from the stack and print the popped elements
    printf("Popping elements from the stack:\n");
    pop();
    pop();

    // Check if the stack is empty and print the result
    if (isEmpty()) {
        printf("The stack is empty\n");
    } else {
        printf("The stack is not empty\n");
    }

    // Push additional elements onto the stack
    push(7);
    push(10);

    // Print the updated stack
    printf("Updated elements of the stack:\n");
    display();

    return 0;
}
