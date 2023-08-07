#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error: Cannot push element into the stack.\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into the stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from the stack\n", temp->data);
    top = top->next;
    free(temp);
}

int isEmpty() {
    return (top == NULL);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        struct Node* current = top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
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
