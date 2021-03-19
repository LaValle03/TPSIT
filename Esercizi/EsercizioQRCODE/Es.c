#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct El{
    int numero ;
    char seme ;
    int random ;
    struct El* next;
};

int is_empty(struct El *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}

void push (struct El **head, struct El* elemento){
    if (is_empty(*head)){
        *head = elemento ;
        elemento->next = NULL ;
    } else {
        elemento->next = *head ;
        *head = elemento ;
    }
}

struct El *pop (struct El **head){
    struct El *ret = *head ;

    if (is_empty(*head)){
        return NULL ;
    } else {
        *head = ret->next ;
    }
    return ret ;
}


void main(){
    struct El *pila = NULL ;
    struct El *appoggio = NULL ;

    struct El *alice = NULL ;
    struct El *bob = NULL ;

    for(int k = 0; k < 4; k++){     //inserimento delle carte all'interno del mazzo (pila)
        for(int j = 1; j < 14; j++){
            appoggio = (struct El*) malloc(sizeof(struct El));

            appoggio->numero = j ;

            if(k == 0){
                appoggio->seme = 'C';
            }
            if(k == 1){
                appoggio->seme = 'P';
            }
            if(k == 2){
                appoggio->seme = 'Q';
            }
            if(k == 3){
                appoggio->seme = 'F';
            }
            if(k > 3){
                printf("ERRORE");
            }

            appoggio->random = (int)rand % 100000 ;

            push(&pila, appoggio);
        }
    }


    for(int k = 0; k < 26; k++){    //distrubuzione delle carte a alice e bob
        int turno = (int)rand % 2 ;

        alice = (struct El*) malloc(sizeof(struct El));
        bob = (struct El*) malloc(sizeof(struct El));

        
        if (turno == 0){
            alice = pop(&pila);
            bob = pop(&pila);
        } else {
            bob = pop(&pila);
            alice = pop(&pila);
        }
        

        printf("ALICE: %d%c\n", alice->numero, alice->seme);        //stampo il mazzo di alice
        //printf("BOB: %d%c\n", bob->numero, bob->seme);
    }
}