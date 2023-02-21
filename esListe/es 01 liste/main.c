#include <stdio.h>
#include <malloc.h>

typedef struct node {
    char* name;
    struct node* next;
} Node;

int main() {
    Node* lista = (Node*) malloc(sizeof(Node));
    lista->name = (char*) malloc(sizeof(char) * 1024);
    printf("nome: ");
    scanf("%s", lista->name);
    printf("%s\n", lista->name);
    lista->next = NULL;

    free(lista);
    return 0;
}
