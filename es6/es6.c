#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

int calcolaSomma(int lunghezza, int array[]) {

    int somma = 0;
   
    for (int *p = array; p < array + lunghezza; p++) {
        somma = somma + *(p);
    }

    return somma;
}

int main() {

    int array[DIM];
    int somma;

    for (int *p = array; p < array + DIM; p++) {
        printf("\ninserisci il numero in posizione [%d]: ", p);
        scanf("%d", p);
    }


    somma = calcolaSomma(DIM, array);
    printf("La somma degli elementi del vettore è: %d\n", somma);

    return 0;
}