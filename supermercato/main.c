#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T_MIN 1
#define T_MAX 4

typedef struct node {
    int n;
    int time;
    struct node* next;
} Persona;

int isEmpty(Persona * queue) {
    return queue == NULL;
}

void enqueue(Persona** head, Persona** tail, Persona* el) {
    if(isEmpty(*head))
        *head = el;
    else
        (*tail)->next = el;
    *tail = el;
    el->next = NULL;

}

Persona* dequeue(Persona** head, Persona** tail) {
    Persona* ret = *head;
    if(isEmpty(*head))
        return NULL;
    *head = ret->next;
    if(isEmpty(*head))
        *tail = NULL;
    return ret;
}

void freeQueue(Persona* queue) {
    if(queue->next != NULL)
        freeQueue(queue->next);
    free(queue);
}

void printQueue(Persona* queue) {
    if(isEmpty(queue))
        return;
    printf(" - numero %d\n", queue->n);
    if(queue->next != NULL)
        printQueue(queue->next);
}

int main() {
    srand(time(NULL));
    Persona* queue = NULL;
    Persona* tailQueue = NULL;

    int intervalloEntrataCliente = rand()%(T_MAX - T_MIN + 1) + T_MIN;
    int timeToServe = -1;
    int nPersona = 1;
    for(int k = 720; k > 0; k--) {
        if(intervalloEntrataCliente == 0) {
            Persona* newP = (Persona*) malloc(sizeof(Persona));
            newP->next = NULL;
            newP->n = nPersona ++;
            newP->time = rand()%(T_MAX - T_MIN + 1) + T_MIN;
            if(timeToServe < 0)
                timeToServe = newP->time;

            enqueue(&queue, &tailQueue, newP);
            printf("persona %d aggiunta alla coda (t = %d)\n", nPersona - 1, newP->time);

            intervalloEntrataCliente = rand()%(T_MAX - T_MIN + 1) + T_MIN;
        } else
            intervalloEntrataCliente --;

        if(timeToServe == 0) {
            Persona* exit = dequeue(&queue, &tailQueue);
            printf("la persona %d ha pagato\n", exit->n);
            exit->next = NULL;
            free(exit);
            if(isEmpty(queue))
                timeToServe = -1;
            else
                timeToServe = queue->time;
        } else
            timeToServe --;
    }

    printf("\nFINE TEMPO\n\npersone ancora dentro:\n");
    printQueue(queue);
    freeQueue(queue);
    tailQueue = NULL;

    return 0;
}
