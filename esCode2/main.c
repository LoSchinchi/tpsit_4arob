#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node* next;
} Node;

Node* createElement(int n) {
    Node* t = (Node*) malloc(sizeof(Node));
    t->n = n;
    t->next = NULL;
    return t;
}

int isEmpty(Node* list) {
    return list == NULL;
}

void enqueue(Node** head, Node** tail, int n) {
    Node* newEl = createElement(n);
    if(isEmpty(*head))
        *head = newEl;
    else
        (*tail)->next = newEl;
    *tail = newEl;
}

Node* dequeue(Node** head, Node** tail) {
    Node* ret = *head;
    if(isEmpty(*head))
        return NULL;
    *head = ret->next;
    if(isEmpty(*head))
        *tail = NULL;
    return ret;
}

void printQueue(Node* queue) {
    if(isEmpty(queue))
        return;
    printf("%d  ", queue->n);
    if(queue->next != NULL)
        printQueue(queue->next);
}

void freeQueue(Node* queue) {
    if(queue->next != NULL)
        freeQueue(queue->next);
    free(queue);
}

int main() {
    Node* head = NULL;
    Node* tail = head;

    for(int i = 0; i < 4; i ++) {
        int n;
        printf("numero da inserire: ");
        scanf("%d", &n);

        enqueue(&head, &tail, n);
    }

    printQueue(head);
    printf("\n");
    while(!isEmpty(head)) {
        Node* deq = dequeue(&head, &tail);
        printQueue(head);
        printf(" -- %d\n", deq->n);
        free(deq);
    }
    return 0;
}
