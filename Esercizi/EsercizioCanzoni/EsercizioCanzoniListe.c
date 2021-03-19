#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100


typedef struct canzone{
    int numero;
    char autore[LUNG];
    char titolo[LUNG];
    int temp;
    struct canzone *next ;
}Canzone;


int main () {
    Canzone *canzone1 ;
    canzone1 = (Canzone*) malloc (sizeof(Canzone)) ;

    //lettura del file
    while (fgets()) {
        Canzone *canzoneTemp ;
        canzoneTemp = (Canzone*) malloc (sizeof(Canzone)) ;
    }
}