/*
author: gabriel bussone
date: 18/09/2023
es. 1
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 200
#define NUM_RIGHE 20000


typedef struct film {

    int numero;
    char* titolo; //char[10]
    char* genere;
    int anno;
    char* disponibilita;

} film ;

int main() {

    char filename[] = "listafilm.csv";
    char riga[NUM_RIGHE];
    FILE *fp;
    char *campo;
    film array_film[NUM_RIGHE];
    int counter = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Impossibile aprire il file");
        exit(1);
    }

    while(fgets(riga, NUM_RIGHE, fp)) {

        campo = strtok(riga, ",");
        array_film[counter].numero = atoi(campo);   // atoi: trasforma una stringa in intero    atof: cinverte da stringa a float

        campo = strtok(NULL, ",");
        array_film[counter].titolo = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].genere = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].anno = atoi(campo);

        campo = strtok(NULL, ",");
        array_film[counter].disponibilita= strdup(campo);


        if (campo != NULL) {
            printf("numero: %d\n", array_film[counter].numero);
            printf("Titolo: %s\n", array_film[counter].titolo);
            printf("Genere: %s\n", array_film[counter].genere);
            printf("Anno: %d\n", array_film[counter].anno);
            printf("Disponibilita: %s\n\n", array_film[counter].disponibilita);
        }

        counter ++;

    }

    return 0;
}


