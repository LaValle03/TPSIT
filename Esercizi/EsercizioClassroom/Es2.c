#include <stdio.h>
#include <stdlib.h>


typedef struct el {
    int valore;
    struct el *next;
} El ;


void push(El* lista, int numero){
    El* l = lista;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = (El*)malloc(sizeof(El));
    l->next->valore = numero;
    l->next->next = NULL;
}

int contaLista(El* lista){
    int k ;
    for(k = 0; lista != NULL; k++) {
        lista = lista->next ;
    }
    return k ;
}

El* trovaStruttura(El* lista, int j) {
    for(int k = 0; k < j; k++) {
        lista = lista->next ;
    }
    return lista ;
}

void stampaLista(El* l){
    while (l != NULL)
    {
        printf("%d\n", l->valore);
        l = l->next; /* assegno ad l l'indirizzo della prossima struttura */
    }
}


El* primo_Pari(El* lista){
    while(lista != NULL){
        if(lista->valore % 2 == 0){
            return lista;
        }
        lista = lista ->next;
    }
    return NULL;
}


int main()
{
    int numero;
    El *lista;
    lista = NULL; /* assegna al punatore di tipo El NULL(cioè nonpunta a niente) */

    do
    {
        scanf("%d", &numero);
        if (numero >= 0)
        {
            if (lista == NULL) /* chiedo se lista non punta a niente */
            {
                /* alloco in memoria una struttura El e l'indirizzo lo assegno a lista, assegno la struttura punatata da lista a l  */

                lista = (El *)malloc(sizeof(El));
                lista->valore = numero;
                lista->next = NULL;

            }
            else /* entra nell'else se lista contiene un indirizzo */
            {
                push(lista, numero);
            }
        }
    } while (numero >= 0);

    stampaLista(lista);
    
    printf("\n");

    lista = primo_Pari(lista);

    printf("%d", lista->valore);
    //printf("%d\n", l->valore);

    
}