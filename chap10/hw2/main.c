#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void addq(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("malloc\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int deleteq() {
    if (head == NULL) {
        printf("queue is empty.\n");
        return -1;
    }
    struct node *temp = head;
    int data = temp->data;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
    return data;
}

int main() {
    int val;

    while (1) {
        if (scanf("%d", &val) != 1 || val <= 0) {
            printf("Print queue\n");
            struct node *current = head;
            while (current != NULL) {
                printf("%d\n", current->data);
                current = current->next;
            }
            break;
        }

        addq(val);
    }

    return 0;
}
