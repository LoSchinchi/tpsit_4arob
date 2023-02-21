#include <stdio.h>

int main() {

    float a = 10;
    float* p = &a;
    float **x = &p; // *x = p;

    //float b = 4;
    //p = &b; -> poi x punta a b

    printf("%f %f %f\n", a, *p, **x);

    scanf("%f", &a);
    scanf("%f", p); // &(*p)
    scanf("%f", *x); // &(**x)
    // & annulla *

    int v[5];
    int* z = v;

    int m[2][3];
    int** y = m;

    // stampare m[1][1]
    printf("%d", m[1][1]); // m[1] è un vettore
    printf("%d", (*y + 1)[1]); // *y + 1 = m[1]
    int* v2 = *y + 1;                // v2 = m[1]
    printf("%d", *(v2 + 1));
    printf("%d", *(*y + 1) + 1);

    return 0;
}
