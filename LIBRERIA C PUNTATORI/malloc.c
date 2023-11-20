#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Chiedi all'utente quanti numeri vuole inserire
    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    // Alloca dinamicamente memoria per un array di interi
    int *numeri = (int *)malloc(n * sizeof(int));

    if (numeri == NULL) {
        printf("Errore nell'allocazione di memoria.\n");
        return 1;
    }

    // Chiedi all'utente di inserire i numeri
    for (int i = 0; i < n; i++) {
        printf("Inserisci il numero %d: ", i + 1);
        scanf("%d", &numeri[i]);
    }

    // Calcola la somma dei numeri
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += numeri[i];
    }

    // Stampa la somma
    printf("La somma dei numeri è: %d\n", somma);

    // Libera la memoria allocata dinamicamente
    free(numeri);

    return 0;
}
