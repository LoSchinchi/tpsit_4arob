#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_STR 20
#define STR_END_SET_LIST "fine"

typedef char* String;
typedef struct node {
    String name;
    struct node* next;
} Node;

void setList(Node* list) {
    String inp;
    Node* last = list;
    int nNode = 1;

    do {
        inp = (String) malloc(sizeof(char) * L_STR);
        printf("nome del nodo %d (oppure %s): ", nNode, STR_END_SET_LIST);
        scanf("%s", inp);
        if(strcmp(inp, STR_END_SET_LIST) != 0) {
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->next = NULL;
            list->next = newNode;
            list->name = inp;
            last = list;
            list = newNode;
            nNode ++;
        }
    } while(strcmp(inp, STR_END_SET_LIST) != 0);

    printf("\n");
    last->next = NULL;
    free(list);
    free(inp);
}

void printList(Node* list, int n) {
    printf("nome del nodo %d: %s\n",n, list->name);
    if(list->next != NULL)
        printList(list->next, n + 1);
}

void freeList(Node *list) {
    if(list->next != NULL)
        freeList(list->next);
    free(list);
}

int main() {
    Node* list = (Node*) malloc(sizeof(Node));

    setList(list);
    printList(list, 1);
    freeList(list);

    return 0;
}