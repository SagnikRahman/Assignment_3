#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to push element into the stack.\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed element %d into the stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    int popVal = temp->data;
    free(temp);
    printf("Popped element %d from the stack.\n", popVal);
}

int isEmpty() {
    return (top == NULL);
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        struct Node* current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    display();

    pop();
    display();

    printf("Is stack empty? Answer: %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
