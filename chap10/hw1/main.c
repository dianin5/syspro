#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Malloc\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct node *temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

void printStack() {
    struct node *current = top;
    printf("Print stack\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    int val;
    printf("Enter values to push:\n");

    while (1) {
        if (scanf("%d", &val) != 1 || val <= 0) {
            printStack();
            break;
        }
        push(val);
    }

    return 0;
}

