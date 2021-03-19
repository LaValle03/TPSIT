#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100


typedef struct canzone{
    int numero;
    char autore[LUNG];
    char titolo[LUNG];
    int temp;
}Canzone;

int leggiFile (Canzone *musica, char nomeFile[]) {
    char *temp = (char*)malloc(sizeof(char)*100);
    int cnt = 0 ;
    FILE *file ;
    file = fopen (nomeFile, "r") ;

    while(fgets(temp, 100, file)) {
        (musica + cnt)->numero = atoi (strtok(temp, ",")) ;
        strcpy ((musica + cnt)->autore, strtok(NULL, ",")) ;
        strcpy ((musica + cnt)->titolo, strtok(NULL, ",")) ;
        cnt++;
    }
    free(temp) ;
    return cnt ;
}

void visualizza (Canzone *musica, int dim) {
    for (int k = 0; k < dim; k++) {
        printf ("%d %s %s\n", (musica + k)->numero, (musica + k)->autore, (musica + k)->titolo);
    }
}

void random (Canzone *musica, int dim) {
    for (int k = 0; k < dim; k++) {
        (musica + k)->temp = rand() % 1000000 ;
    }

    for (int k = dim - 1; k > 0; k--) {
        for (Canzone *j = musica; j - musica < k; j++) {
            if (j->temp > (j + 1)->temp) {
                Canzone temp ;
                temp = *j ;
                *j = *(j+1) ;
                *(j+1) = temp ;
            }
        }
    }

}


void main(){
    Canzone *musica = (Canzone*) malloc(sizeof(Canzone)*LUNG);
    char nomeFile[LUNG] = "canzoni.csv" ;
    int dim = leggiFile (musica, nomeFile) ;

    printf ("CANZONI IN ORDINE\n");
    visualizza (musica, dim) ;

    random (musica, dim) ;

    printf ("\nCANZONI RANDOM\n") ;
    visualizza (musica, dim) ;
}