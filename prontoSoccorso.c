#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct paziente{
    char nome[50];
    int eta;
    char colore[10];
    struct paziente* next;
}Paziente;

typedef struct coda{
    Paziente* head;
}Coda;

bool is_empty(Coda* coda){
    return coda->head == NULL;
}

void push(Coda* coda, Paziente* paziente){
    if(is_empty(coda)){
        coda->head = paziente;
        paziente->next = NULL;
    }
    else{
        paziente->next = coda->head;
        coda->head = paziente;
    }
}

Paziente* pop(Coda* coda){
    Paziente* paziente;
    if(is_empty(coda)){
        return NULL;
    }
    else{
        paziente = coda->head;
        coda->head = paziente->next;
    }
    return paziente;
}

void print_paziente(Paziente* paziente){
    printf("Nome: %s, Età: %d, Colore: %s\n", paziente->nome, paziente->eta, paziente->colore);
}

void gestisci_pazienti(Coda* coda){
    Paziente* paziente;
    Paziente* pazienti_verdi = NULL;
    Paziente* pazienti_gialli = NULL;
    Paziente* pazienti_bianchi = NULL;
    Paziente* pazienti_rossi = NULL;
    while(!is_empty(coda)){
        paziente = pop(coda);
        if(paziente->colore[0] == 'r'){
            push(&pazienti_rossi, paziente);
        }
        else if(paziente->colore[0] == 'g'){
            push(&pazienti_gialli, paziente);
        }
        else if(paziente->colore[0] == 'v'){
            push(&pazienti_verdi, paziente);
        }
        else{
            push(&pazienti_bianchi, paziente);
        }
    }
    while(!is_empty(pazienti_rossi)){
        paziente = pop(&pazienti_rossi);
        print_paziente(paziente);
        free(paziente);
    }
    while(!is_empty(pazienti_gialli)){
        paziente = pop(&pazienti_gialli);
        print_paziente(paziente);
        free(paziente);
    }
    while(!is_empty(pazienti_verdi)){
        paziente = pop(&pazienti_verdi);
        print_paziente(paziente);
        free(paziente);
    }
    while(!is_empty(pazienti_bianchi)){
        paziente = pop(&pazienti_bianchi);
        print_paziente(paziente);
        free(paziente);
    }
}

int main(){
    Coda* coda = (Coda*)malloc(sizeof(Coda));
    Paziente* paziente;
    char nome[50], colore[10];
    int eta;
    printf("Inserisci il nome del paziente: ");
    scanf("%s", nome);
    printf("Inserisci l'età del paziente: ");
    scanf("%d", &eta);
    printf("Inserisci il colore di priorità del paziente (rosso, giallo, verde, bianco): ");
    scanf("%s", colore);
    paziente = (Paziente*)malloc(sizeof(Paziente));
    strcpy(paziente->nome, nome);
    paziente->eta = eta;
    strcpy(paziente->colore, colore);
    push(coda, paziente);
    printf("Paziente inserito con successo.\n);

}