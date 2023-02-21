#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char par;
    char opp;
    struct node* next;
} Node;

Node* createNode(char c) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->next = NULL;
    n->par = c;
    if(c == '{')
        n->opp = '}';
    else if(c == '[')
        n->opp = ']';
    else
        n->opp = ')';

    return n;
}

bool isEmpty(Node* list) {
    return list == NULL;
}

void push(Node** head, char c) {
    Node* el = createNode(c);
    if(!isEmpty(*head))
        el->next = *head;
    *head = el;
}

Node* pop(Node** head) {
    if(isEmpty(*head))
        return  NULL;
    Node* ret = *head;
    *head = ret->next;
    return ret;
}

void freeList(Node* l) {
    if(l->next != NULL)
        freeList(l->next);
    free(l);
}

int main() {
    Node* pila = NULL;
    char* s = (char*) malloc(sizeof (char) * 50);
    printf("espressione: ");
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i ++) {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            push(&pila, s[i]);
        else if(s[i] == '}' || s[i] == ']' || s[i] == ')') {
            Node *last = pop(&pila);
            if (last->opp != s[i]) {
                printf("errore al carattere %d, parentesi necessaria: %c\n", i + 1, last->opp);
                freeList(pila);
                return 0;
            }
            free(last);
        }
    }

    if(!isEmpty(pila)) {
        printf("errore, c'è almeno una parentesi non chiusa\n");
        freeList(pila);
    } else
        printf("espressione corretta");

    return 0;
}
