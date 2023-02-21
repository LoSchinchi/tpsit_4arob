/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>

typedef struct  node
{
    int  valore;
    struct  node* next;
}Node;

void printList(Node* l) {
    printf("%d - %p \n",l->valore, l->next);
    if(l->next != NULL)
        printList(l->next);
}

int nNodes(Node* l) {
    if(l != NULL)
        return nNodes(l->next) + 1;
    return 0;
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare: ");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima iterazione  */
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);

    printList(lista);
    printf("nodi: %d\n", nNodes(lista));

    return  0;
}
