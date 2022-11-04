//
// Autore: Francesco Canonico
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

Vgsales split(String s) {
    Vgsales vg;

    vg.rank = atoi(strtok(s, ","));
    vg.name = strtok(NULL, ",");
    vg.platform = strtok(NULL, ",");
    vg.year = atoi(strtok(NULL, ","));
    vg.genre = strtok(NULL, ",");
    vg.publisher = strtok(NULL, ",");
    vg.NA_Sales = (float) atof(strtok(NULL, ","));
    vg.EU_Sales = (float) atof(strtok(NULL, ","));
    vg.JP_Sales = (float) atof(strtok(NULL, ","));
    vg.Other_Sales = (float) atof(strtok(NULL, ","));
    vg.Global_Sales = (float) atof(strtok(NULL, ","));

    return vg;
}

int dimFile() {
    int k = 0;
    String riga = (String) malloc(sizeof(char) * L_STR);
    FILE* fp = fopen("vgsales.csv", "r");
    while(fgets(riga, L_STR, fp))
        k ++;
    fclose(fp);
    return k - 1;
}

int main() {
    int _dim = dimFile();
    Vgsales* vg = (Vgsales*) malloc(sizeof(Vgsales) * _dim);
    Vgsales* p = vg;
    String riga = (String) malloc(sizeof(char) * L_STR);

    FILE* fp = fopen("vgsales.csv", "r");
    fgets(riga, L_STR, fp);

    while(!feof(fp) && p - vg < _dim) {
        riga = (String) malloc(sizeof(char) * L_STR);
        fgets(riga, L_STR, fp);
        riga = (String) realloc(riga, (strlen(riga) + 1) * sizeof(char));
        *p = split(riga);
        printf("%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f\n",
               p->rank, p->name, p->platform, p->year,
               p->genre, p->publisher, p->NA_Sales, p->EU_Sales,
               p->JP_Sales, p->Other_Sales, p->Global_Sales);
        p ++;
    }

    free(riga);
    free(vg);
    fclose(fp);

    return 0;
}
