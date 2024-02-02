#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct {
    Nodo* testa;
} Pila;

void inizializzaPila(Pila* pila) {
    pila->testa = NULL;
}

void push(Pila* pila, int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovoNodo == NULL) {
        printf("Errore nell'allocazione di memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuovoNodo->dato = valore;
    nuovoNodo->next = pila->testa;
    pila->testa = nuovoNodo;
}

int pop(Pila* pila) {
    if (pila->testa == NULL) {
        printf("Errore: la pila è vuota.\n");
        exit(EXIT_FAILURE);
    }
    Nodo* nodoRimosso = pila->testa;
    int valore = nodoRimosso->dato;
    pila->testa = nodoRimosso->next;
    free(nodoRimosso);
    return valore;
}

void stampaPariPrimaDispari(int* sequenza, int lunghezza) {
    Pila pila;
    inizializzaPila(&pila);

    for (int i = 0; i < lunghezza; i++) {
        if (sequenza[i] % 2 == 0) {
            push(&pila, sequenza[i]);
        }
    }

    for (int i = 0; i < lunghezza; i++) {
        if (sequenza[i] % 2 != 0) {
            push(&pila, sequenza[i]);
        }
    }

    printf("Stampa dei pari prima dei dispari:\n");
    while (pila.testa != NULL) {
        printf("%d ", pop(&pila));
    }
    printf("\n");
}

int main() {
    int sequenza[] = {1, 20, 35, 40, 62, 51, 66};
    int lunghezza = sizeof(sequenza) / sizeof(sequenza[0]);

    stampaPariPrimaDispari(sequenza, lunghezza);

    return 0;
}
