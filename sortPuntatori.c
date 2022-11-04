#include <stdio.h>
#include <malloc.h>

void scambia(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int* p, int n) {
    for(int* i = p + 1; i - p < n; i ++)
        for(int* j = p; j < i; j ++)
            if(*i < *j)
                scambia(i, j);
}

int main() {
    int dim;
    printf("dim: ");
    scanf("%d", &dim);

    if(dim < 0)
        return 0;

    int* array = (int*) malloc(sizeof(int) * dim);
    int* p = array;
    for(int k = 0; k < dim; k ++) {
        printf("array[%d]: ", k);
        scanf("%d", p + k);
    }

    for(int k = 0; k < dim; k ++)
        printf("%5d", *(p + k));
    printf("\n\n");

    sort(array, dim);
    for(int k = 0; k < dim; k ++)
        printf("%5d", *(p + k));
    printf("\n");

    return 0;
}
