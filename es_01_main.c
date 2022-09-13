//
// Autore: Francesco Canonico
//

#include <stdio.h>
#include <stdbool.h>

#define L_STR 1024

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
void setInt(int* k, String s, int* n) {
    *n = 0;
    while(s[*k] != ',') {
        *n = *n * 10 + charToInt(s[*k]);
        *k += 1;
    }
    *k += 1;
}
void setFloat(int* k, String s, float* n) {
    bool virgolaPassata = false;
    *n = 0;
    int div;

    while(s[*k] != ',' && s[*k +1] != '\0') {
        if(s[*k] == '.') {
            div = 10;
            virgolaPassata = true;
        } else {
            if(!virgolaPassata)
                *n = *n * 10 + (float) charToInt(s[*k]);
            else {
                div *= 10;
                *n += (float) charToInt(s[*k]) / (div / 10);
            }
        }
        *k += 1;
    }
    *k += 1;
}
void setString(int* k, String s, String ret) {
    int c = 0;
    while(s[*k] != ',') {
        ret[c] = s[*k];
        c ++;
        *k += 1;
    }
    ret[c] = '\0';
    *k += 1;
}

Vgsales split(String s) {
    Vgsales ret;
    int k = 0;

    setInt(&k, s, &ret.rank);
    setString(&k, s, ret.name);
    setString(&k, s, ret.platform);
    setInt(&k, s, &ret.year);
    setString(&k, s, ret.genre);
    setString(&k, s, ret.publisher);
    setFloat(&k, s, &ret.NA_Sales);
    setFloat(&k, s, &ret.EU_Sales);
    setFloat(&k, s, &ret.JP_Sales);
    setFloat(&k, s, &ret.Other_Sales);
    setFloat(&k, s, &ret.Global_Sales);

    return ret;
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

    Vgsales arr[nRighe];
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("not found");
        return 0;
    }
    fgets(riga, L_STR, fp);
    for(int k = 0; k < nRighe; k ++) {
        fgets(riga, L_STR, fp);
        arr[k] = split(riga);
    }
    fclose(fp);
    for(int k = 0; k < nRighe; k ++)
        printf("%d,%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n",
               arr[k].rank, arr[k].name, arr[k].platform, arr[k].year,
               arr[k].genre, arr[k].publisher, arr[k].NA_Sales, arr[k].EU_Sales,
               arr[k].JP_Sales, arr[k].Other_Sales, arr[k].Global_Sales);

    return 0;
}
