#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define PATH_FILE_READER "dati.csv"
#define DIM_STR 1024

typedef struct {
    char* nome;
    char* cognome;
    int dataNascita;
} Persona;

bool existFile() {
    FILE* fp = fopen(PATH_FILE_READER, "r");
    bool x = fp;
    fclose(fp);
    return x;
}
int dim() {
    FILE *fp = fopen(PATH_FILE_READER, "r");
    int r = 0;
    char *line = (char *) malloc(sizeof(char) * DIM_STR);
    while (fgets(line, DIM_STR, fp))
        r++;

    free(line);
    fclose(fp);
    return r;
}
void readFromFile(Persona* persone) {
    Persona* p = persone;
    FILE* fp = fopen(PATH_FILE_READER, "r");

    char *line = (char *) malloc(sizeof(char) * DIM_STR);
    while (fgets(line, DIM_STR, fp)) {
        p->cognome = strdup(strtok(line, ","));
        p->nome = strdup(strtok(NULL, ","));
        p->dataNascita = atoi(strtok(NULL, ","));
        p ++;
    }
    free(line);
    fclose(fp);
}
void sortArray(Persona* persone, int _dim) {
    for(Persona* i = persone + 1; i - persone < _dim; i ++)
        for(Persona* j = persone; j < i; j ++)
            if(i->dataNascita < j->dataNascita) {
                Persona t = *i;
                *i = *j;
                *j = t;
            }
}

int main() {
    if(!existFile())
        return 0;

    int _dim = dim();
    Persona* persone = (Persona*) malloc(sizeof(Persona) * _dim);

    readFromFile(persone);
    sortArray(persone, _dim);

    Persona* p = persone;
    while(p - persone < _dim) {
        printf("%s %s %d\n", p->cognome, p->nome, p->dataNascita);
        p++;
    }

    free(persone);

    return 0;
}
