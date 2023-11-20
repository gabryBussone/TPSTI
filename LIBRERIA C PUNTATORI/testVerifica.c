#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define LUNG 50
#define MAX_RIGHE 100

typedef struct {

    char cognome[LUNG];
    int quota;

} Studente;

int calcolaTotale(Studente* studenti, int numStudenti) {

    int totale = 0;

    for (int i = 0; i < numStudenti; i++) {
        totale = totale + (studenti + i)->quota;
    }
    if (totale == 2200) {
        printf("incasso raggiunto correttamente");
    } else {
        printf("\nmanca %d euro per raggiungere l'incasso necessario", 2200 - totale);
    }

    return totale;
}

void cercaNome(Studente* studenti, int numStudenti, char* nome) {

    for (int i = 0; i < numStudenti; i++) {
        if (strcmp((studenti + i)->cognome, nome) == 0) {
            if ((studenti + i)->quota == 100) {
                printf("%s ha pagato l'incasso necessario\n", nome);
            } else {
                printf("%s ha ancora %d euro da pagare\n", nome, 100 - (studenti + i)->quota);
            }
            return;
        }
    }
    printf("nome non trovato");
}

int contaRighe(char* nomeFile) {

    char riga[MAX_RIGHE];
    int cont = 0;

    FILE* file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("errore apertura file");
        exit(1);
    }

    while (fgets(riga, MAX_RIGHE, file)) {
        cont++;
    }

    fclose(file);
    return cont;
}

int main() {

    char* nomeFile = "4AROB_GITA.CSV";
    char* data;
    char* cognome;
    char* soldiVersati;
    int euroVersati;
    int totaleIncassi;
    char nomeCercato[LUNG];
    int numStudenti = 0;
    char righe[MAX_RIGHE];

    int numRighe = contaRighe(nomeFile);

    FILE* file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("errore apertura file");
        exit(1);
    }

    Studente* studenti = (Studente*)malloc(numRighe * sizeof(Studente));

    while (fgets(righe, MAX_RIGHE, file)) {

        data = strtok(righe, ";");
        cognome = strtok(NULL, ";");
        soldiVersati = strtok(NULL, ";");

        euroVersati = atoi(soldiVersati);

        strcpy((studenti + numStudenti)->cognome, cognome);
        (studenti + numStudenti)->quota = euroVersati;

        numStudenti++;
    }

    totaleIncassi = calcolaTotale(studenti, numStudenti);
    printf("totale euro incassati: %d\n", totaleIncassi);

    printf("inserisci il nome che vuoi cercare: ");
    scanf("%s", nomeCercato);

    cercaNome(studenti, numStudenti, nomeCercato);

    for (int i = 0; i < numStudenti; i++) {

        printf("%s %d", (studenti + i)->cognome, (studenti + i)->quota);
        if ((studenti + i)->quota != 100) {
            printf("        DA CONTROLLARE");
        }
        printf("\n");
    }

    free(studenti);

    fclose(file);
}



