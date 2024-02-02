#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Pila {
    int cima;
    int capacita;
    char* array;
}Pila;

struct Pila* creaPila(int capacita) {

    struct Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->capacita = capacita;
    pila->cima = -1;
    pila->array = (char*)malloc(pila->capacita * sizeof(char));
    return pila;
}

int pilaVuota(Pila* pila) {

    return pila->cima == -1;
}

int pilaPiena(Pila* pila) {

    return pila->cima == pila->capacita - 1;
}

void push(Pila* pila, char elemento) {

    if (pilaPiena(pila))
        return;
    pila->array[++pila->cima] = elemento;
}

char pop(Pila* pila) {

    if (pilaVuota(pila))
        return '\0';
    return pila->array[pila->cima--];
}

int palindromo(char* stringa) {

    int lunghezza = strlen(stringa);
    struct Pila* pila = creaPila(lunghezza);

    for (int i = 0; i < lunghezza / 2; i++) {
        push(pila, stringa[i]);
    }

    for (int i = (lunghezza + 1) / 2; i < lunghezza; i++) {
        if (pop(pila) != stringa[i]) {
            free(pila->array);
            free(pila);
            return 0;
        }
    }

    free(pila->array);
    free(pila);
    return 1;
}

int main() {

    char a[MAX_LENGTH];

    printf("Inserisci una stringa: ");
    fgets(a, MAX_LENGTH, stdin);

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (a[i] == '\n') {
            a[i] = '\0';
        }
    }

    if (palindromo(a)) {
        printf("la stringa inserita è palindroma\n");
    } else {
        printf("la stringa inserita non è palindroma\n");
    }

    return 0;
}