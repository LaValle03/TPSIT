//Autore: La Valle Nicolò
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DIM 100

typedef struct drone {      //struttura per il file Volo_drone.csv
    int tempo ;
    float latitudine ;
    float longitudine ;
} Drone ;

typedef struct droneAn {    //struttura per il file Anomalie_drone.csv
    int tempo;
    char anomalia[DIM];
} DroneAn ;


int leggiVoloDrone (Drone *drone, int dim) {            //funzione che legge il file Volo_drone.csv e salva i dati all'interno della struttura
    char *temp = (char*)malloc(sizeof(char)*100);       //dichirazione di un puntatore a stringa che salva le singole righe del file
    int cnt = 0 ;
    FILE *file ;
    file = fopen ("Volo_drone.csv", "r") ;


    if (file == NULL) {
        printf ("Il file non esiste") ;
    } else {
        fgets (temp, 100, file) ;
        while(fgets(temp, 100, file) && cnt < dim) {            //while che legge tutte le righe del file, le separa con strtok e le salva all'interno della struttura
            (drone + cnt)->tempo = atoi (strtok(temp, ",")) ;
            (drone + cnt)->latitudine = atof (strtok(NULL, ",")) ;
            (drone + cnt)->longitudine = atof (strtok(NULL, ",")) ;
            
            cnt++ ;
        }
        free (temp) ;       //libero la memoria occupata da questo puntatore a stringa
        return cnt ;        //dimensione effettiva della struttura
    }
}

int leggiAnomalie (DroneAn *drone2, int dim) {      //funzione che legge il file Anomalie_drone.csv e salva i dati all'interno della struttura
    char *temp = (char*)malloc(sizeof(char)*100);
    int cnt = 0 ;
    FILE *file ;
    file = fopen ("Anomalie_drone.csv", "r") ;

    if (file == NULL) {
        printf ("Il file non esiste") ;
    } else {
        fgets (temp, 100, file) ;
        while(fgets(temp, 100, file) && cnt < dim) {        //while che legge tutte le righe del file, le separa con strtok e le salva all'interno della struttura
            (drone2 + cnt)->tempo = atoi (strtok(temp, ",")) ;
            strcpy ((drone2 + cnt)->anomalia, strtok(NULL, ",")) ;
            
            cnt++ ;
        }
        free (temp) ;       //libero la memoria occupata da questo puntatore a stringa
        return cnt ;
    }
}

int main () {
    Drone *drone = (Drone*) malloc(sizeof(Drone)*DIM);
    DroneAn *droneAn = (DroneAn*) malloc(sizeof(DroneAn)*DIM) ;

    int dim = leggiVoloDrone (drone, DIM) ;

    int dim2 = leggiAnomalie (droneAn, DIM) ;

    for (int k = 0; k < dim2; k++) {        //for che cerca i le coordinate associate ai tempi delle anomalie
        for (int j = 0; j < dim; j++) {
            if ((drone + j)->tempo == (droneAn + k)->tempo) {
                printf ("%d %f %f %s", (drone + j)->tempo, (drone + j)->latitudine, (drone + j)->longitudine, (droneAn + k)->anomalia) ;    //output delle coordinate associate alle anomalie
            }
        }
    }
    //libero la memoria occupata attraverso la funzione free
    free (drone) ;
    free (droneAn) ; 
}