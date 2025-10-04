#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 3
int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    if (top == -1) 
        return true;
    return false;
}

bool isFull() {
    if (top == MAX_SIZE - 1) 
        return true;
    return false;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return; 
    }
    printf("popped value: %d\n", stack[top--]);
}

void display() {
    if(isEmpty())
        printf("Stack is Empty\nNothing to print !\n");
    else {
        for(int i=0; i<=top; i++)
            printf("%d\t", stack[i]);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Is Empty\n5. Is Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is not Empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Stack is Full\n");
                else
                    printf("Stack is not Full\n");
                break;
            case 6:
                printf("--- Program Exited ---\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}