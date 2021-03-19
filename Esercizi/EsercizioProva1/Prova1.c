#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main () {
    int N ;
    float R ;

    printf ("Inserisci R: ") ;
    scanf ("%f", &R) ;

    printf ("Inserisci il numero di alunni: ") ;
    scanf ("%d", &N) ;

    int giorno = 1 ;
    float vettore [N] ;

    vettore[0] = 1 ;

    do {
        vettore[giorno] = R * vettore[giorno - 1] ;
        giorno++ ;
    } while (vettore[giorno - 1] < N) ;

    for (int k = 0; k < giorno; k++) {
        printf ("Giorno %d: %.0f contagiati\n", k + 1, vettore[k]) ;
    }
}