//
// Created by fre on 15/09/22.
//

#include <stdio.h>

int main() {
    int v[5];
    int* p = v;

    for(int k = 0; k < 5; k ++)
        *(p + k) = k * k;
    // (*(p + k)).rank = ...;
    for(int k = 0; k < 5; k ++)
        printf("[%d] -> %d\n", k, *(p + k));
    printf("\n");

    while(p - v < 5)
        printf("[%d] -> %d\n", (int)(p - v - 1), *p++);

    return 0;
}