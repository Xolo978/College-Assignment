#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 50

char stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    if(top == -1)
        return true;
    return false;
}

bool isFull() {
    if(top == MAX_SIZE-1)
        return true;
    return false;
}

void push(char value) {
    if(isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

void isParenthesisMatching(char expr[]) {
    int len = strlen(expr);
    for(int i = 0; i < len; i++) {
        char ch = expr[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            if(isFull()) {
                printf("Stack Overflow\n");
                return;
            }
            push(ch);
        } else if(ch == ')') {
            if(isEmpty()) {
                printf("\nUnmatched Parenthesis\n");
                return;
            } else if(stack[top] == '(') {
                pop();
            } else {
                printf("\nUnmatched Parenthesis\n");
                return;
            }
        } else if(ch == '}') {
            if(isEmpty()) {
                printf("\nUnmatched Parenthesis\n");
                return;
            } else if(stack[top] == '{') {
                pop();
            } else {
                printf("\nUnmatched Parenthesis\n");
                return;
            }
        } else if(ch == ']') {
            if(isEmpty()) {
                printf("\nUnmatched Parenthesis\n");
                return;
            } else if(stack[top] == '[') {
                pop();
            } else {
                printf("\nUnmatched Parenthesis\n");
                return;
            }
        }
    }

    if(!isEmpty()) {
        printf("\nUnmatched Parenthesis\n");
    } else {
        printf("\nMatched Parenthesis\n");
    }
}

int main() {
    char expr[50];
    printf("Enter the expression: ");
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        return 1;
    }
    int len = strlen(expr);
    if (len > 0 && expr[len-1] == '\n') {
        expr[--len] = '\0';
    }
    top = -1;

    isParenthesisMatching(expr);
    printf("--- Program Exited ---\n\n");
    return 0;
}