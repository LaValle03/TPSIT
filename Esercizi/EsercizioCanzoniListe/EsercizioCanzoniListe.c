#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct canzone{
    int numero;
    char autore[100];
    char titolo[100];
    int valore;
    struct canzone* next;
}Canzone;


void leggiFile(Canzone* musica, FILE* file, int *k){
    char* riga = (char *) malloc(sizeof(char) * 200);
    Canzone* t = musica;
    while(fgets(riga, 200, file)){
        t->numero = atoi(strtok(riga, ","));
        strcpy(t->autore, (strtok(NULL, ",")));
        strcpy(t->titolo, strtok(NULL, ","));
        t->next = (Canzone*) malloc(sizeof(Canzone)); 
        t->valore = rand() % 10000000 ;
        t = (t->next);
        *k += 1; 
        free(riga);
        riga = (char *)malloc(sizeof(char)*200);      
    }
    free(t);
}


Canzone* canzoneSelezionata(Canzone* musica, int numero){
    Canzone* t = musica;
    for(int i = 0; i < numero; i++){
        t=t->next ;
    }
    return t;
}


void canzoniRandom(Canzone* musica, int k){
    int massimo ;
    int posizioneFinale ;
    Canzone* t;

    for(int j = 0; j < k; j++){
        t = musica ;
        posizioneFinale = 0 ;
        massimo = t->valore;
        for(int x = 0; x < k; x++){
            if(massimo < t->valore){
                massimo = t->valore;
                posizioneFinale = x ;
            }
            t = t->next;
        }
        t = canzoneSelezionata(musica, posizioneFinale) ;
        printf ("%d %s %s\n",t->numero, t->titolo, t->autore) ;
        t -> val = -100 - posizioneFinale ;
    }
}


void main(){
    srand(time(NULL));
    FILE *file;

    if((file = fopen("canzoni.csv","r")) == NULL){
        printf("Il file non esiste");
    }else{
        int k = 0 ;
        
        Canzone* musica = (Canzone *) malloc(sizeof(Canzone));
        leggiFile(musica, file, &k);
        
        fclose(file);

        for (int j = 0; j < k; j++) {
            Canzone* t ;
            t = canzoneSelezionata(musica, j) ;
            printf ("%d %s %s \n", t->numero, t->titolo, t->autore) ;
        }

        canzoniRandom(musica, k);
        free(musica) ;
    }
}