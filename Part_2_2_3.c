#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Cannot push element into the stack.\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return '\0'; // Return a sentinel value
    } else {
        char poppedVal = top->data;
        struct Node* temp = top;
        top = top->next;
        free(temp);
        return poppedVal;
    }
}

int isParenthesesMatch(const char *exp) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char popped = pop();
            if (popped == '\0') {
                return 0; // Unbalanced, unmatched closing parenthesis
            }
            
            if ((exp[i] == ')' && popped != '(') || (exp[i] == '}' && popped != '{') || (exp[i] == ']' && popped != '[')) {
                return 0; // Unbalanced
            }
        }
    }
    
    return (top == NULL); // If the stack is empty, the parentheses are balanced
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression with parentheses: ");
    scanf("%s", exp);
    if (isParenthesesMatch(exp)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are unbalanced.\n");
    }
    return 0;
}
