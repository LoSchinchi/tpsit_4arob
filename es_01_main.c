//
// Autore: Francesco Canonico
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXGAME 1024
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

void gameWitEUhSalesMaxPerPublisher(Vgsales arr[], int dim, String publisher) {
    bool primoUscito = false;
    Vgsales t;

    for (int k = 0; k < dim; k++) {
        if (!strcmp(publisher, arr[k].publisher)) {
            if (!primoUscito) {
                t = arr[k];
                primoUscito = true;
            } else if (arr[k].Global_Sales / arr[k].EU_Sales > t.Global_Sales / t.EU_Sales)
                t = arr[k];
        }
    }

    if (!primoUscito)
        printf("nessun gioco di %s\n", publisher);
    else
        printf("\nIl massimo delle vendite in europa per un gioco %s in base alle vendite totali sono del gioco \"%s\"\n",publisher, t.name);
}

int main() {
    FILE* fp = fopen("vgsales.csv", "r");
    if(fp == NULL)
        return 0;

    String riga;
    Vgsales vg[MAXGAME];
    int k = 0;
    fgets(riga, L_STR, fp);

    while(!feof(fp) && k < MAXGAME) {
        fgets(riga, L_STR, fp);

        vg[k].rank = atoi(strtok(riga, ","));
        vg[k].name = strtok(NULL, ",");
        vg[k].platform = strtok(NULL, ",");
        vg[k].year = atoi(strtok(NULL, ","));
        vg[k].genre = strtok(NULL, ",");
        vg[k].publisher = strtok(NULL, ",");
        vg[k].NA_Sales = atof(strtok(NULL, ","));
        vg[k].EU_Sales = atof(strtok(NULL, ","));
        vg[k].JP_Sales = atof(strtok(NULL, ","));
        vg[k].Other_Sales = atof(strtok(NULL, ","));
        vg[k].Global_Sales = atof(strtok(NULL, ","));

        printf("%d,%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n",
               vg[k].rank, vg[k].name, vg[k].platform, vg[k].year,
               vg[k].genre, vg[k].publisher, vg[k].NA_Sales, vg[k].EU_Sales,
               vg[k].JP_Sales, vg[k].Other_Sales, vg[k].Global_Sales);
        k ++;
    }

    fclose(fp);
    gameWitEUhSalesMaxPerPublisher(vg, MAXGAME, "Nintendo");

    return 0;
}
