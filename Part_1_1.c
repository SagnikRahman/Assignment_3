#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed element %d into the stack.\n", value);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow");
    } else {
        int popVal = stack[top];
        top--;
        printf("Popped element %d from the stack.\n", popVal);
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
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    printf("Is stack empty? Answer: %s\n", isEmpty() ? "Yes" : "No");
    printf("Is stack full? Answer: %s\n", isFull() ? "Yes" : "No");
    return 0;
}
