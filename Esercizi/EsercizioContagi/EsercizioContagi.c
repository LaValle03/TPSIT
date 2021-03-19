#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 20
#define DIM 50


typedef struct regione{
    char data[LUNG];
    char stato[LUNG];
    int codice_regione;
    char denominazione_regione[LUNG];
    float lat;
    float longit;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
}Regione;

int leggiFile (Regione *regioni, char nomeFile[]) {
    char *temp = (char*)malloc(sizeof(char)*200);
    int cnt = 0 ;
    FILE *file ;
    file = fopen (nomeFile, "r") ;

    while(fgets(temp, 200, file)) {
        
        strcpy((regioni+cnt)->data ,strtok(temp,","));
        strcpy((regioni+cnt)->stato ,strtok(NULL,","));
        (regioni+cnt)->codice_regione=atoi(strtok(NULL,","));
        strcpy((regioni+cnt)->denominazione_regione,strtok(NULL,","));
        (regioni+cnt)->lat=atof(strtok(NULL,","));
        (regioni+cnt)->longit=atof(strtok(NULL,","));
        (regioni+cnt)->ricoverati_con_sintomi=atoi(strtok(NULL,","));
        (regioni+cnt)->terapia_intensiva=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_ospedalizzati=atoi(strtok(NULL,","));
        (regioni+cnt)->isolamento_domiciliare=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->variazione_totale_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->nuovi_positivi=atoi(strtok(NULL,","));
        (regioni+cnt)->dimessi_guariti=atoi(strtok(NULL,","));
        (regioni+cnt)->deceduti=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_sospetto_diagnostico=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_da_screening=atoi(strtok(NULL,","));
        (regioni+cnt)->totale_casi=atoi(strtok(NULL,","));
        (regioni+cnt)->tamponi=atoi(strtok(NULL,","));
        (regioni+cnt)->casi_testati=atoi(strtok(NULL,","));
        cnt++;
    }
    return cnt ;

    free(regioni) ;
}

void riordinaRicoverati (Regione *regioni, int dim) {           //bubble sort per riordinare in base ai ricoverati in terapia intensiva  
    for (int k = dim - 1; k > 0; k--) { 
        for (Regione *j = regioni; j - regioni < k; j++) {
            if (j->terapia_intensiva < (j + 1)->terapia_intensiva) {
                //funzione scambio
                Regione temp ;
                temp = *j ;
                *j = *(j + 1) ;
                *(j + 1) = temp ;
            }
        }
    }
    free(regioni) ;
}

int calcoloRicoverati (Regione *regioni, int dim) {
    int somma = 0 ;
    for (int k = 0; k < dim; k++) {
        somma = somma + (regioni + k)->terapia_intensiva ;
    }
    free(regioni) ;
    return somma ;
}

void riordinaCasiTot (Regione *regioni, int dim) {
    for (int k = dim - 1; k > 0; k--) {
        for (Regione *j = regioni; j - regioni < k; j++) {
            if (j->totale_casi > (j + 1)->totale_casi) {
                Regione temp ;
                temp = *j ;
                *j = *(j + 1) ;
                *(j + 1) = temp ;
            }
        }
    }
    free(regioni) ;
}




int main() {
    Regione *regione = (Regione*) malloc(sizeof(Regione)*50);
    char nomeFile[DIM] = "contagi.csv" ;
    
    int dim = leggiFile (regione, nomeFile) ;

    riordinaRicoverati (regione, dim) ;
    
    printf ("TOP 3 TERAPIA INTENSIVA: %s %s %s\n", (regione)->denominazione_regione, (regione + 1)->denominazione_regione, (regione + 2)->denominazione_regione);

    printf ("TOTALE RICOVERATI: %d\n", calcoloRicoverati(regione, dim));
    riordinaCasiTot (regione, dim) ;
    printf ("TOP 3 CASI POSITIVI: %s %s %s", (regione)->denominazione_regione, (regione + 1)->denominazione_regione, (regione + 2)->denominazione_regione);

    free(regione) ;
}