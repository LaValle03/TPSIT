#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct el{
    int valore;
    struct el* next;
}El;


void push(El* lista, int numero){
    //El* l = lista;
    while(lista->next != NULL){
        lista = lista->next;
    }
    lista->next = (El*)malloc(sizeof(El));
    lista->next->valore = numero;
    lista->next->next = NULL;
}

El* inserisciLista(El* lista){     //funzione che inserisce numeri positivi all'interno di una lista
    int numero ;
    
    do{
        scanf("%d", &numero);
        if (numero >= 0) {
            if (lista == NULL){
                lista = (El *)malloc(sizeof(El));
                lista->valore = numero;
                lista->next = NULL;
            } else {
                push(lista, numero);
            }
        }
    }while(numero >= 0);

    return lista ;
}

El* inserisciListaDim(El *lista, int dim) {
    for (int k = 0; k < dim; k++) {
        int numero ;
        scanf("%d", &numero);

        if (lista == NULL) {
            lista = (El *)malloc(sizeof(El));
            lista->valore = numero;
            lista->next = NULL;
        } else {
            push(lista, numero);
        }
    }

    return lista ;
}

El* trovaStruttura(El* lista, int j) {  //trova la cella di una lista passando la posizione
    for(int k = 0; k < j; k++) {
        lista = lista->next ;
    }
    return lista ;
}

int contaLista(El* lista){  //conta il numero di celle di una lista
    int k ;
    for(k = 0; lista != NULL; k++) {
        lista = lista->next ;
    }
    return k ;
}

int contaLista_ricorsiva(El* lista){    //funzione ricorsiva che conta il numero di celle in una lista
    if(lista == NULL){
        return 0;
    } else {
        return 1 + contaLista_ricorsiva(lista->next);
    }
}

void deallocaLista(El* lista){      //funzione ricorsiva che libera lo spazio in memoria di una lista
    if(lista != NULL){
        deallocaLista(lista->next);

        free(lista);
        printf("free: %d\n", lista->valore);
    }
}

/*
El* bubbleSort(El* lista, int dim) {
    for(int k = dim - 1; k > 0; k--){
        for(int j = 0; j < dim; j++){
            if(trovaStruttura(lista, j) > trovaStruttura(lista, j + 1)){
                El* l ;
                l = (El *)malloc(sizeof(El));
                l = trovaStruttura(lista, j) ;
                lista = trovaStruttura(lista, j) ;
                lista = trovaStruttura(lista, j + 1);
                printf("CIAO");
                lista = l ;
            }
        }
    }
    return lista ;
}
*/

void stampaLista(El* lista){    //funzione non ricorsiva che stampa la lista
    while (lista != NULL) {
        printf("%d  ", lista->valore);
        lista = lista->next;
    }
}

void stampaLista_ricorsiva(El* lista){      //funzione ricorsiva che stampa la lista
    if(lista != NULL){
        printf("%d  ", lista->valore);
        stampaLista_ricorsiva(lista->next);
    }
}


int main() {
    El* lista ;
    lista = NULL ;

    printf("Inserisci lista: \n");
    lista = inserisciLista(lista);

    printf("Lista con %d elementi: ", contaLista_ricorsiva(lista));
    stampaLista_ricorsiva(lista);
}


//NODO: Singola struttura di una lista
//HEAD: Prima struttura della lista, il primo nodo
//LINK: Puntatore che connette le varie strutture della lista
//LISTA: E' un insieme organizzato di strutture autoreferenziali
//AUTOREFERENZIALI: Le strutture che puntano ognuna alla successiva