#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 200
#define NUM_RIGHE 20000


typedef struct film {

    int numero;
    char* titolo; 
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
    int i;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Impossibile aprire il file");
        exit(1);
    }

    while(fgets(riga, NUM_RIGHE, fp)) {

        campo = strtok(riga, ",");
        (array_film + counter)->numero = atoi(campo);   // atoi: trasforma una stringa in intero    atof: cinverte da stringa a float

        campo = strtok(NULL, ",");
        (array_film + counter)->titolo = strdup(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->genere = strdup(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->anno = atoi(campo);

        campo = strtok(NULL, ",");
        (array_film + counter)->disponibilita= strdup(campo);

        counter ++;

        for(i = 0; i<= counter; i++) {
            printf("numero: %d\n", (array_film + i)->numero);
            printf("Titolo: %s\n", (array_film + i)->titolo);
            printf("Genere: %s\n", (array_film + i)->genere);
            printf("Anno: %d\n", (array_film + i)->anno);
            printf("Disponibilita: %s\n\n", (array_film + i)->disponibilita);
        }


    }

    return 0;
}