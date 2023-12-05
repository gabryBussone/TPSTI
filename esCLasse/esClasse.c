#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *successivo;
} Nodo;

Nodo *testa = NULL;

void inserisciInTesta(int x) {
    Nodo *nuovoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuovoNodo->valore = x;
    nuovoNodo->successivo = testa;
    testa = nuovoNodo;
}

int rimuoviDaTesta() {
    if (testa == NULL) {
        printf("Lista vuota\n");
        return -1;
    }
    int x = testa->valore;
    Nodo *temp = testa;
    testa = testa->successivo;
    free(temp);
    return x;
}

void stampaLista() {
    Nodo *temp = testa;
    while (temp!= NULL) {
        printf("%d ", temp->valore);
        temp = temp->successivo;
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Inserisci il numero di elementi della lista: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int x;
        printf("Inserisci il numero %d: ", i+1);
        scanf("%d", &x);
        inserisciInTesta(x);
    }

    printf("La lista è: ");
    stampaLista();

    for (i = 0; i < n; i++) {
        int x = rimuoviDaTesta();
        printf("Elemento rimosso: %d\n", x);
    }

    printf("La lista è: ");
    stampaLista();

    return 0;
}
