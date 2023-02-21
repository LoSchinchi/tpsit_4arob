#include <stdio.h>
#include <stdlib.h>

#define DIM_ARRAY 6

typedef struct node {
    int val;
    struct node* next;
} Node;

Node* arrayToList(Node* array) {
    Node* list = (Node*) malloc(sizeof(Node));
    Node* head = list;
    Node* prev = NULL;
    for(Node* node = array; node - array < DIM_ARRAY; node ++) {
        list->val = node->val;
        prev = list;
        list->next = (Node*) malloc(sizeof(Node));
        list = list->next;
    }
    prev->next = NULL;
    free(list);

    return head;
}

int size(Node* l) {
    if(l != NULL)
        return size(l->next) + 1;
    return 0;
}

Node* listToArray(Node* list) {
    int dim = size(list);
    Node* array = (Node*) malloc(sizeof(Node) * dim);
    for(Node* node = array; node - array < dim; node ++, list = list->next) {
        node->val = list->val;
        node->next = NULL;
    }
    return array;
}

void printList(Node* list) {
    printf("val: %d\n", list->val);
    if(list->next != NULL)
        printList(list->next);
}

void freeList(Node* list) {
    if(list->next != NULL)
        freeList(list->next);
    free(list);
}

void printArray(Node* array, int dim) {
    for(Node* node = array; node - array < dim; node ++)
        printf("val: %d\n", node->val);
}

int main() {
    Node* array = (Node*) malloc(sizeof(Node) * DIM_ARRAY);
    int k = 0;
    for(Node* n = array; n - array < DIM_ARRAY; n ++, k ++) {
        n->val = k + 1;
        n->next = NULL;
    }

    Node* list = arrayToList(array);
    printList(list);
    free(array);

    Node* newArr = listToArray(list);
    printArray(newArr, size(list));

    freeList(list);
    free(newArr);

    return 0;
}
