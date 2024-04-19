//BUSSONE GABRIEL

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTI 5


typedef struct numero{
    int numero_arrivo;
    int valore;
} Numero;

typedef struct coda{
    Numero numeri[NUM_ELEMENTI];
    int x;
} Coda;

typedef struct pila{
    Numero numeri[NUM_ELEMENTI];
    int x;
} Pila;

void enqueue(Coda* coda, Numero numero) {
    if (coda->x < NUM_ELEMENTI) {
        coda->numeri[coda->x] = numero;
        coda->x++;
    }
}

Numero dequeue(Coda* coda) {
    Numero numero = coda->numeri[0];
    for (int i = 0; i < coda->x - 1; i++) {
        coda->numeri[i] = coda->numeri[i + 1];
    }
    coda->x;
    return numero;
}

void push(Pila* pila, Numero numero) {
    if (pila->x < NUM_ELEMENTI) {
        pila->numeri[pila->x] = numero;
        pila->x++;
    }
}

Numero pop(Pila* pila) {
    Numero numero = pila->numeri[pila->x - 1];
    pila->x--;
    return numero;
}

void print_coda(Coda coda) {
    printf("Coda:\n");
    for (int i = 0; i < coda.x; i++) {
        printf("numero d'arrivo: %d e valore: %d\n", coda.numeri[i].numero_arrivo, coda.numeri[i].valore);
    }
}

void print_pila(Pila pila) {
    printf("Pila:\n");
    for (int i = pila.x - 1; i >= 0; i--) {
        printf("numero d'arrivo: %d e valore: %d\n", pila.numeri[i].numero_arrivo, pila.numeri[i].valore);
    }
}

int main() {
    
    srand(time(NULL));
    
    Coda coda;
    coda.x = 0;
    
    Pila pila;
    pila.x = 0;
    
    for (int i = 0; i < NUM_ELEMENTI; i++) {
        Numero numero;
        numero.numero_arrivo = i + 1;
        numero.valore = rand() % 10 + 1;
        enqueue(&coda, numero);
        
        numero.valore = rand() % 10 + 1;
        push(&pila, numero);
    }
    
    print_coda(coda);
    print_pila(pila);
    
    while (coda.x > 0 && pila.x > 0) {
        Numero numero_coda = dequeue(&coda);
        Numero numero_pila = pop(&pila);
        
        printf("\nscontro tra numero %d della coda e numero %d della pila\n", numero_coda.numero_arrivo, numero_pila.numero_arrivo);
        
        if (numero_coda.valore < numero_pila.valore) {
                        printf("vincitore della coda: %d\n", numero_coda.numero_arrivo);
            if (numero_pila.valore - numero_coda.valore > 0) {
                numero_pila.valore -= numero_coda.valore;
                enqueue(&coda, numero_pila);
            }
        } else if (numero_coda.valore > numero_pila.valore) {
            printf("vincitore della pila: %d\n", numero_pila.numero_arrivo);
            if (numero_coda.valore - numero_pila.valore > 0) {
                numero_coda.valore -= numero_pila.valore;
                push(&pila, numero_coda);
            }
        } else {
            printf("PARITA': ENTRAMBI I GIOCATORI ELIMINATI\n");
        }
    }
    
    printf("\nSTRUTTURA CODA:\n");
    print_coda(coda);
    
    printf("\nSTRUTTURA PILA:\n");
    print_pila(pila);
    
    if (coda.x > 0) {
        printf("\nvincitori code:\n");
        for (int i = 0; i < coda.x; i++) {
            printf("numero d'arrivo: %d e valore: %d\n", coda.numeri[i].numero_arrivo, coda.numeri[i].valore);
        }
    } else if (pila.x > 0) {
        printf("\nvincitori pile:\n");
        for (int i = pila.x - 1; i >= 0; i--) {
            printf("Numero arrivo: %d e valore: %d\n", pila.numeri[i].numero_arrivo, pila.numeri[i].valore);
        }
    } else {
        printf("\nNON HA VINTO NESSUNO\n");
    }
    
    return 0;
}