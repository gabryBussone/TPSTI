#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//definizione della costante per il max di elementi dentro pila e coda
#define NUM_ELEMENTI 5

// creazione delle strutture
typedef struct numero
{
    int numero_arrivo;
    int valore;
} Numero;

typedef struct coda
{
    Numero numeri[NUM_ELEMENTI];
    int x:
} Coda;

typedef struct pila
{
    Numero numeri[NUM_ELEMENTI];
    int x;
} Pila;

// creazioni funzioni enqueue e dequeue per la coda
void enqueue(Coda *coda, Numero numero)
{
    if (coda->x < NUM_ELEMENTI)
    {
        coda->numeri[coda->x] = numero;
        coda->x++;
    }
}

Numero dequeue(Coda *coda)
{
    Numero numero = coda->numeri[0];
    for (int i = 0; i < coda->x - 1; i++)
    {
        coda->numeri[x] = coda->numeri[i + 1];
    }
    coda->x--;
    return numero;
}

// creazioni funzioni push e pop per la pila
void push(Pila *pila, Numero numero)
{
    if (pila->x < NUM_ELEMENTI)
    {
        pila->numeri[pila->x] = numero;
        pila->x++;
    }
}

Numero pop(Pila *pila)
{
    Numero numero = pila->numeri[pila->x - 1];
    pila->x--;
    return numero;
}

//stampa della pila e della coda
void stampa_coda(Coda coda)
{
    printf("coda:\n");
    for (int i = 0; i < coda.x; i++)
    {
        printf("numero d'arrivo: %d e valore: %d\n", coda.numeri[i].numero_arrivo, coda.numeri[i].valore);
    }
}

void stampaPila(Pila pila)
{
    printf("pila:\n");
    for (int i = pila.x; i > 0; i--)
    {
        printf("numero d'arrivo: %d e valore: %s\n", pila.numeri[i - 1].numero_arrivo, pila.numeri[i - 1].valore);
    }
}

int main()
{

    srand(time(NULL));

    Coda coda;
    coda.x = 0;

    Pila pila;
    pila.x = 0;

    for (int i = 0; i < NUM_ELEMENTI; i++)
    {
        Numero numero;
        numero.numero_arrivo = i + 1;
        numero.valore = rand() % 10 + 1;
        enqueue(&coda, numero);

        numero.valore = rand() % 10 + 1;
        push(&pila, numero);
    }

    stampa_coda(coda);
    stampaPila(pila);

    //dopo i controlli del while entra nel ciclo e da vita allo scontro
    while (coda.x > 0 && pila.x > 0)
    {

        Numero numero_coda = dequeue(&coda);
        Numero numero_pila = pop(&pila);

        // inizio dello scontro
        printf("\nscontro tra numero %d della coda e numero %d della pila\n", numero_coda.numero_arrivo, numero_pila.numero_arrivo);

        if (numero_coda.valore < numero_pila.valore)
        {
            printf("vincitore coda: %d\n", numero_coda.numero_arrivo);
            if (numero_pila.valore - numero_coda.valore > 0)
            {
                numero_pila.valore -= numero_coda.valore;
                enqueue(&coda, numero_pila);
            }
        }
        else if (numero_coda.valore > numero_pila.valore)
        {
            printf("vincitore pila: %d\n", numero_pila.numero_arrivo);
            if (numero_coda.valore - numero_pila.valore > 0)
            {
                numero_coda.valore -= numero_pila.valore;
                push(&pila, numero_coda);
            }
        }
        else
        {
            //elimino i due numeri che si sono scontrati sia da pila che da coda
            printf("PARITA': ENTRAMBI I GIOCATORI SONO ELIMINATI\n");
            coda.x--;
            pila.x--:
        }
    }

    //stampo pila e coda dopo lo scontro
    printf("\nSTRUTTURA CODA:\n");
    stampa_coda(coda);

    printf("\nSTRUTTURA PILA:\n");
    stampaPila(pila);

    // stampa i vinctiori
    if (coda.x > 0)
    {
        printf("\nVVINCITORI CODA:\n");
        for (int i = 0; i < coda.x; i++)
        {
            printf("numero d'arrivo: %d e valore: %d\n", coda.numeri[i].numero_arrivo, coda.numeri[i].valore);
        }
    }
    else if (pila.x > 0)
    {
        printf("\nVICNETORI PILA:\n");
        for (int i = pila.x; i > 0; i--)
        {
            printf("numero d'arrivo: %d e valore: %d\n", pila.numeri[i - 1].numero_arrivo, pila.numeri[i - 1].valore);
        }
    }
    else
    {
        printf("\nNON HA VINTO NESSUNO\n");
    }

    return 0;
}