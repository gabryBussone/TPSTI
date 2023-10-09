#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

int calcolaSomma(int lunghezza, int *pVettore) {

    int somma = 0;
    int *puntatoreCorrente = pVettore;

   
    for (int i = 0; i < lunghezza; i++) {
        somma += *puntatoreCorrente;
        puntatoreCorrente++;
    }

    return somma;
}

int main() {

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int somma;

    somma = calcolaSomma(DIM, array);
    printf("La somma degli elementi del vettore è: %d\n", somma);

    return 0;
}