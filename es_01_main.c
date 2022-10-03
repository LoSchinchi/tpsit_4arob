//
// Autore: Francesco Canonico
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXGAME 64
#define L_STR 1024

typedef char* String;

typedef struct {
    int rank;
    String name;
    String platform;
    int year;
    String genre;
    String publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
} Vgsales;

void gameWitEUhSalesMaxPerPublisher(Vgsales* arr, int dim, String publisher) {
    bool primoUscito = false;
    Vgsales t;

    for (int k = 0; k < dim; k++) {
        if (!strcmp(publisher, (*(arr + k)).publisher)) {
            if (!primoUscito) {
                t = (*(arr + k));
                primoUscito = true;
            } else if ((arr + k)->Global_Sales / (arr + k)->EU_Sales > t.Global_Sales / t.EU_Sales)
                t = (*(arr + k));
        }
    }

    if (!primoUscito)
        printf("nessun gioco di %s\n", publisher);
    else
        printf("\nIl massimo delle vendite in europa per un gioco %s in base alle vendite totali sono del gioco \"%s\"\n",publisher, t.name);
}

Vgsales split(String s) {
    Vgsales vg;

    vg.rank = atoi(strtok(s, ","));
    vg.name = strtok(NULL, ",");
    vg.platform = strtok(NULL, ",");
    vg.year = atoi(strtok(NULL, ","));
    vg.genre = strtok(NULL, ",");
    vg.publisher = strtok(NULL, ",");
    vg.NA_Sales = (float)atof(strtok(NULL, ","));
    vg.EU_Sales = (float)atof(strtok(NULL, ","));
    vg.JP_Sales = (float)atof(strtok(NULL, ","));
    vg.Other_Sales = (float)atof(strtok(NULL, ","));
    vg.Global_Sales = (float)atof(strtok(NULL, ","));

    return vg;
}

int main() {
    FILE* fp = fopen("vgsales.csv", "r");
    if(fp == NULL)
        return 0;

    char c[L_STR];
    char* riga = c;
    Vgsales vgS[MAXGAME];
    Vgsales* vg = vgS;

    int k = 0;
    fgets(riga, L_STR, fp);

    while(!feof(fp) && k < MAXGAME) {
        *(vg + k) = split(fgets(riga, L_STR, fp));
        printf("%d,%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n",
               (vg + k)->rank, (vg + k)->name, (vg + k)->platform, (vg + k)->year,
               (vg + k)->genre, (vg + k)->publisher, (vg + k)->NA_Sales, (vg + k)->EU_Sales,
               (vg + k)->JP_Sales, (vg + k)->Other_Sales, (vg + k)->Global_Sales);
        k ++;
    }

    fclose(fp);
    gameWitEUhSalesMaxPerPublisher(vg, MAXGAME, "Nintendo");

    return 0;
}
