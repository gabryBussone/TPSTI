typedef struct Node{
    int valore;
    struct Node* next;
}Node;

int main(){

    int n;
    Node* lista = NULL;
    Node* l;

    do{
        if(lista == NULL){
            lista = (Node*) malloc(sizeof(Node));
            l = lista;
        }else{
            l->next = (Node*) malloc(sizeof(Node));
            l = l->next;
        }

        l->valore = n;
        l->next = NULL 
    }

   l=lista;
    printf("numeri inseriti: ");
        while (l!=NULL)
        {
            printf("%d - %p \n",l->valore, l->next);
            l=l->next;
        }   
    printf("\n");
    return 0;
}


Studente* studente;

studente = (Studente*) malloc(5*sizeof(Studente));


int a[DIM];
int *p;
p = a;
for( int *p = a; p < a + DIM, p++){

}

for(k = 0; k <= DIM; k++){

}

for(k)


void aggiungi(Node** lista, int valore){

    Node* nuovoNodo = (Node*) malloc(sizeof(Node))

    if(nuovoNodo != NULL){
        nuovoNodo->valore = valore;
        nuovoNodo->next = *lista;
        *lista = nuovoNodo;
    }
}

void aggiungi(Node** lista, int valore){

    Node* nuovoNodo = (Node*) malloc(sizeof(Node));

    if(lista != NULL){
        nuovoNodo->valore = valore;
        nuovoNodo->next = *lista;
        *lista = nuovoNodo;
    }
}

int lung(Node* lista){

    if(lista != NULL){
        lung++;
        lista = lista->next;
    }
}

void stampa(Node* lista){

    if(lista != NULL){
        printf("%d", lista->valore)
        stampa(lista->next)
    }
}

typedef struct Node{
    int valore;
    struc Node* next;
}Node;

int main(){

    Node* lista = NULL;
    Node* l;

    if(lista == NULL){
        lista = (Node*) malloc(sizeof(Node));
        l = lista;
    }else{
        l->next = (Node*) malloc(sizeof(Node));
        l = l->next
    }

    l->valore = NULL
    l->next = valore


    l = lista

    if (l != NULL){
        printf("%d - %p", l->valore, l->next);
        l = l->next;
    }
}


void aggiungi(Node** lista, int valore){
    Node* nuovoNodo = (Node*) malloc(sizeof(Node));

    if(lista != NULL){
        lista->valore = valore;
        lista->next= *lista;
        *lista = nuovoNodo;
    }
}

void stampaRicorsiva(Node* lista){

    if(lista != NULL){
        printf("%d", lista->valore);
        stampaRicorsiva(lista->next);
    }
}

int lung(Node* lista){

    int lung;
     
     if(lista != NULL){
        lung++;
        lista = lista->next
     }
     return lung;
}


void aggiungiInFondo(Node** testa, int valore) {
    Node* nuovoNodo = (Node*)malloc(sizeof(Node));
    Node* ultimo = *testa;

    if (nuovoNodo != NULL) {
        nuovoNodo->valore = valore;
        nuovoNodo->next = NULL;

        // Se la lista è vuota, il nuovo nodo diventa la testa
        if (*testa == NULL) {
            *testa = nuovoNodo;
        } else {
            // Altrimenti, trova l'ultimo nodo e collega il nuovo nodo
            while (ultimo->next != NULL) {
                ultimo = ultimo->next;
            }
            ultimo->next = nuovoNodo;
        }
    } else {
        printf("Errore: Impossibile allocare memoria per il nuovo nodo.\n");
        exit(EXIT_FAILURE);
    }
}
