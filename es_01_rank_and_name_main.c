//
// Autore: Francesco Canonico
//

#include <stdio.h>
#include <string.h>

#define L_STR 1024
#define MAX_DIM_ARRAY 1024

typedef char String[L_STR];

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

int main() {
    FILE* fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("not found");
        return 0;
    }
    int nRighe = 0;
    String riga;
    fgets(riga, L_STR, fp);
    while(!feof(fp)) {
        fflush(fp);
        fgets(riga, L_STR, fp);

        nRighe ++;
    }
    fclose(fp);

    if(nRighe > MAX_DIM_ARRAY)
        nRighe = MAX_DIM_ARRAY;
    Vgsales arr[nRighe];

    fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("not found");
        return 0;
    }
    fgets(riga, L_STR, fp);
    for(int k = 0; k < nRighe; k ++) {
        fscanf(fp, "%d,", &arr[k].rank);
        fgets(riga, L_STR, fp);
        int c = 0;
        while (riga[c] != ',') {
            arr[k].name[c] = riga[c];
            c ++;
        }
    }
    fclose(fp);

    for(int k = 0; k < nRighe; k ++)
        printf("%d,%s\n", arr[k].rank, arr[k].name);

    return 0;
}
