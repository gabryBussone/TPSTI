#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

void scambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(int *vett, int n) {
    int k, sup, sca;
    sup = n - 1;

    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup; k++) {
            if (*(vett + k) > *(vett + k + 1)) {
                scambio(vett + k, vett + k + 1);
                sca = k;
            }
        }
        sup = sca;
    }
}

int main() {
    int v[DIM] = {9, 2, 5, 1, 7, 6, 4, 8, 3, 0};

    bubbleSort3(v, DIM);

    printf("Array ordinato:\n");
    for (int i = 0; i < DIM; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
