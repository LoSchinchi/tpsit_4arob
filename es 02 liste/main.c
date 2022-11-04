#include <stdio.h>
#include <malloc.h>

typedef struct node {
    char* name;
    struct node* next;
} Node;

int main() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->name = "Node 1";
    head->next = (Node*) malloc(sizeof(Node));
    head->next->name = "Node 2";
    head->next->next = NULL;

    printf("%s\n%s\n", head->name, head->next->name);
    free(head->next);
    free(head);
    return 0;
}
