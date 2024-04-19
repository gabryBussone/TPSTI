#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct container{
    int codice;
    float peso;
    float tara;
    struct container* next;
}Container;

bool is_empty(Container* head){
    return head == NULL;
}

void push(Container** head, Container* element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Container* pop(Container** head){
    Container* stack;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

void print_stack(Container* head){
    Container* s = head;
    while(s!= NULL){
        printf("Codice: %d, Peso: %.2f, Tara: %.2f\n", s->codice, s->peso, s->tara);
        s = s->next;
    }
}

int main(){
    Container* head;
    Container* el;
    char car = 'n';
    int codice, peso, tara;
    while(car == 'n'){
        head = (Container*)malloc(sizeof(Container));
        el = (Container*)malloc(sizeof(Container));
        printf("Inserisci il codice del Container: ");
        scanf("%d", &codice);
        el->codice = codice;
        printf("Inserisci il peso del Container: ");
        scanf("%f", &peso);
        el->peso = peso;
        printf("Inserisci la tara del Container: ");
        scanf("%f", &tara);
        el->tara = tara;
        push(&head, el);
        head = head->next;
        printf("Vuoi inserire un altro Container? (s o n): ");
        fflush(stdin);
        scanf("%c", &car);
    }
    print_stack(head);
    free(head); free(el);
    return 0;
}


modifica questo esercizio con questo, non mettere i commenti e utilizza nomi in italiano: abbiamo due strutture una di tipo coda e uan di tipo pila. sia la struttura pila che che la struttura coda sono composti da 5 elementi. questi elementi sono composti da un NUMERO_ARRIVO (quindi un numero da 1 a 5 dato dall'ordine di arrivo) e un numero casuale tra 1 e 10 chiamato VALORE. 1 procedere alla creazione di una struttura CODA e una struttura PILA. 2 procedere al caricamento di 5 elementi per ogni struttura (funzioni enqueue e push). 3 stampare la struttura CODA e la struttura PILA appena create. 4 e ora andiamo allo scontro. prendi il VALORE del primo elemento che dovrà uscire dalla struttura PILA (pop) e confontalo con il VALORE dle primo elemento che dovrà uscire dalla struttura CODA (dequeue): chi avrà valore MINORE verrà eliminato, chi avrà valore MAGGIOREverrà rimesso nella stessa struttura (enqueue o push) diminuito del VALORE dell'elemento della struttura avversaria, se pari verranno eliminati entrambi. infine stampare ad ogni scontro NUMERO_ARRIVO e VALORE degli elementi interessati e il vincitore (se presente) con il nuovo VALORE. perde la struttura che rimarrà senza elementi (potete gestire il numero di elementi presenti nelle 2 strutture con 2 variabili contatori. stampare tutti gli elementi (NUMERO_ARRIVO, VALORE) della struttura vincente.

