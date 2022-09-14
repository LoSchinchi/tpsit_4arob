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

int charToInt(char c) {
    if(c == '0')
        return 0;
    else if(c == '1')
        return 1;
    else if(c == '2')
        return 2;
    else if(c == '3')
        return 3;
    else if(c == '4')
        return 4;
    else if(c == '5')
        return 5;
    else if(c == '6')
        return 6;
    else if(c == '7')
        return 7;
    else if(c == '8')
        return 8;
    else
        return 9;
}

void setrankAndName(char *s, Vgsales *v) {
    int k = 0, c = 0;
    v->rank = 0;
    while(s[k] != ',') {
        v->rank = v->rank * 10 + charToInt(s[k]);
        k ++;
    }
    k ++;
    while(s[k] != ',') {
        v->name[c] = s[k];
        c ++;
        k ++;
    }
    v->name[c] = '\0';
}

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
        fgets(riga, L_STR, fp);
        setrankAndName(riga, &arr[k]);
    }
    fclose(fp);

    for(int k = 0; k < nRighe; k ++)
        printf("%d,%s\n", arr[k].rank, arr[k].name);

    return 0;
}
