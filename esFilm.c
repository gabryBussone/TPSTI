#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct film {
    char titolo[50];
    int anno;
    char genere[20];
    struct film* next;
} Film;

int is_empty(Film* top) {
    return top == NULL;
}

void push(Film** top, Film* movie) {
    movie->next = *top;
    *top = movie;
}

Film* pop(Film** top) {
    if (is_empty(*top)) {
        return NULL;
    }
    Film* popped = *top;
    *top = popped->next;
    return popped;
}

void printStack(Film* top) {
    Film* current = top;
    printf("Pila:\n");
    while (current != NULL) {
        printf("Titolo: %s, Anno: %d, Genere: %s\n", current->titolo, current->anno, current->genere);
        current = current->next;
    }
}

void freeStack(Film* top) {
    if (top != NULL) {
        freeStack(top->next);
        free(top);
    }
}

int main() {
    Film* top = NULL;
    Film* movie = (Film*)malloc(sizeof(Film));

    printf("Inserisci i dati del film:\n");
    printf("Titolo: ");
    scanf("%s", movie->titolo);

    printf("Anno: ");
    scanf("%d", &movie->anno);

    printf("Genere: ");
    scanf("%s", movie->genere);

    movie->next = NULL;

    push(&top, movie);
    printStack(top);

    Film* poppedMovie = pop(&top);

    if (poppedMovie != NULL) {
        printf("\nFilm estratto dalla pila:\n");
        printf("Titolo: %s, Anno: %d, Genere: %s\n", poppedMovie->titolo, poppedMovie->anno, poppedMovie->genere);
        free(poppedMovie);
    }

    printStack(top);
    freeStack(top);

    return 0;
}
