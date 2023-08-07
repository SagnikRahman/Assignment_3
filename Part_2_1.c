#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(char val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0'; // Return a sentinel value
    } else {
        return stack[top--];
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
    
    return isEmpty(); // If the stack is empty, the parentheses are balanced
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
