#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define DIM 100

void encoding (char stringa[]) {        //funzione che comprime la stringa
    int cnt = 1 ;
    for (int k = 0; stringa[k] != '\0'; k++) {      //for che legge tutta la stringa
        if (stringa[k] == stringa[k + 1]) {     
            cnt++ ;
        } else {
            printf ("%d%c", cnt, stringa[k]) ;     
            cnt = 1 ;
        }
    }
    printf("\n") ;
}

void decoding (char stringa[]) {        //funzione che decomprime la funzione
    for (int k = 0; stringa[k] != '\0'; k++) {      //for che legge tutta la stringa
        if (stringa[k] >= '0' && stringa[k] <= '9') {       //se il carattere è un numero
            for (int j = 1; j < stringa[k] - 48; j++) {
                printf ("%c", stringa[k + 1]) ;         //output del carattere ripetuto
            } 
        } else {
            printf ("%c", stringa[k]) ;     //output del singolo carattere
        }
    }
    printf ("\n") ;
}


void main () {
    char stringa [DIM] ;
    int scelta ;
    

    do {        //ciclo finche non si inserisce 0
        printf ("Inserisci una stringa: ") ;
        scanf ("%s", stringa) ;

        printf ("\n0 - Esci\n1 - Encoding\n2 - Decoding\nFai la tua scelta: ") ;
        scanf ("%d", &scelta) ;

        switch (scelta) {       //menù che sceglie se comprimere o decomprimere
            case 0:
                
            break;

            case 1:
                encoding (stringa) ;
            break;

            case 2:
                decoding (stringa) ;
            break;
            
            default:
                printf ("ERRORE") ;
            break;
        }
    } while (scelta != 0) ;   
}