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

void bubbleSort3(int vett[], int n) {

    int k, sup, sca;
    sup = n - 1;

    while (sup > 0) {
        sca = 0;
        for (int *p = vett; p < vett + n; p++) {
            if (*p > *(p + 1)) {
                scambio(p, p + 1);
                sca = p - vett;
            }
        }
        sup = sca;
    }
}

int main() {
    int v[DIM] = {9, 2, 5, 1, 7, 6, 4, 8, 3, 0};

    bubbleSort3(v, DIM);

    printf("Array ordinato:\n");
    for (int *p = v; p < v + DIM; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
