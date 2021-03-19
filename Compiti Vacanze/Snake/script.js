"use strict"
const DIM = 20; // costante dimensione campo

var campo; // Vettore campo da gioco

var direzione = "dx"; // Direzione dello snake all'avvio

var lunghezzaSnake = 1 ;

var boolPerso = false ;

let xCibo, yCibo; 

var refBody ;

/* costanti per colori */
const GRIGIO = "rgb(127, 127, 127)";
const BIANCO = "rgb(255, 255, 255)"; // #FFFFFF
const ROSSO = "rgb(255, 0, 0)";
const BLU = "rgb(0, 0, 255)";
const ARANCIO = "rgb(255, 117, 20)" ;

/* POSIZIONE SNAKE */
var posSn_x = 1; // coordinata x snake
var posSn_y = 1; // coordinata y snake
var coda = new Array(); // array contenente le posizioni dello snake

/* PER MEMORIZZARE IL TIMEOUT */
var tOut; 

function avvia() {
    initMatrice(); // inizializzare matrice di gioco 
    disegnaCampo(); // disegno grafica campo 

    

    coda.push(posSn_x + "," + posSn_y); // carico in coda posizione iniziale serpente

    // Generazione del cibo su coordinate random x, y 
    generaCibo();

    // Coloriamo la testa dello snake
    document.getElementById("btn_" + posSn_x + "_" + posSn_y).style.backgroundColor = BLU;
    muoviSnake();
}

function initMatrice() {
    campo = new Array(DIM);
    for (let i = 0; i < DIM; i++) {
        campo[i] = new Array(DIM);
    }
    for (let i = 0; i < DIM; i++) {
        for (let j = 0; j < DIM; j++) {
            campo[i][j] = 0;
        }
    }
}

function disegnaCampo() { 
    // refBody = document.getElementById('campo_gioco');
    refBody = document.getElementsByTagName("body")[0]; 

    var tabella = document.createElement("table");

    var cella, riga, btn;

    refBody.appendChild(tabella); // in campo_gioco {div} => inserisco componente html table {tabella}

    tabella.style.margin = "20px auto";
    tabella.style.borderSpacing = "0";

    for (let i = 0; i < DIM; i++) {
        riga = document.createElement("tr");
        tabella.appendChild(riga);
        for (let j = 0; j < DIM; j++) {
            //matrice[i][j] = 0;
            // creazione cella
            cella = document.createElement("td");
            cella.style.width = "18px";
            riga.appendChild(cella);
            //creazione pulsante
            btn = document.createElement("input");
            btn.type = "button";
            btn.id = "btn_" + i + "_" + j; // btn_riga_colonna
            btn.style.width = "18px";
            btn.style.height = "15px";
            btn.style.backgroundColor = GRIGIO;
            btn.style.color = BIANCO;
            // setto evento
            btn.setAttribute("onClick", "get_coord(this);");

            cella.appendChild(btn);
        }
    }
}

function get_coord(btn) {
    // btn_2_4
    let vect = btn.id.split("_");
    alert(vect[1] + " " + vect[2]);
}

function generaCibo() {
    coda.reverse () ;

    xCibo = Math.floor(DIM * Math.random());
    yCibo = Math.floor(DIM * Math.random());

    for (var k = 0 ; k < lunghezzaSnake; k++) {
        let vect = coda[k].split(",");
        if (vect[0] == xCibo && vect[1] == yCibo) {
            xCibo = Math.floor(DIM * Math.random());
            yCibo = Math.floor(DIM * Math.random());
            k-- ;
        }
    }

    coda.reverse () ;

    let pulsante = document.getElementById("btn_" + xCibo + "_" + yCibo);

    pulsante.style.backgroundColor = ROSSO;
    campo[xCibo][yCibo] = 2; // matrice assegno valore 2 in posizione cibo 
    /*
     MATRICE CAMPO
     0 => cella vuota
     1 => snake
     2 => cibo
     */
}

function muoviSnake() {
    if (campo [posSn_x][posSn_y] == 2) {
        campo [xCibo][yCibo] = 0 ;
        lunghezzaSnake++ ;
        generaCibo () ;
    }

    // 1. intercettare la direzione dx, sx, up, dw
    switch (direzione) {
        /*
         0 1 0 0 0 0 0 0 0  
         0 0 0 0 0 0 0 0 0  
         0 0 0 0 0 0 0 0 0 
         0 0 0 0 0 0 0 0 0
         */
        case 'dx':
            posSn_y++; 
            break;
        case 'sx':
            posSn_y--; 
            break;
        case 'up':
            posSn_x--;
            break;
        case 'dw':
            posSn_x++;
            break;
    }
    controlloToccoBordo () ;
    coda.push (posSn_x + "," + posSn_y) ;

    if (!boolPerso) {
        resettaSnake();
        stampaSnake();
    }
    
    controlloToccoCoda () ;
    // 4. timout
    if (!boolPerso) {
        tOut = setTimeout("muoviSnake();", 200); 
    }
}

function cambiaDirezione(event) {
    let codice = event.keyCode;
    if (codice == 37) {
        if (direzione != "dx") {
            direzione = "sx"; 
        }
    }
    if (codice == 38) {
        if (direzione != "dw") {
            direzione = "up"; 
        }
    }
    if (codice == 39) {
        if (direzione != "sx") {
            direzione = "dx"; 
        }
    }
    if (codice == 40) {
        if (direzione != "up") {
            direzione = "dw"; 
        }
    }
}

function resettaSnake() {
    for (let i = 0; i < DIM; i++) {
        for (let j = 0; j < DIM; j++) {
            if (document.getElementById("btn_" + i + "_" + j).style.backgroundColor == BLU) {
                document.getElementById("btn_" + i + "_" + j).style.backgroundColor = GRIGIO;
            }
        }
    }
}

function stampaSnake() {
    coda.reverse () ;
    
    for (var k = 0; k < lunghezzaSnake; k++) {
        let vect = coda[k].split(",");
        document.getElementById("btn_" + vect[0] + "_" + vect[1]).style.backgroundColor = BLU;
    }
    coda.reverse () ;
}

function controlloToccoCoda () {
    coda.reverse () ;
    
    for (var k = 1; k < lunghezzaSnake; k++) {
        let vect = coda[k].split(",");
        if (posSn_x == vect[0] && posSn_y == vect[1]) {
            haiperso () ;
        }
    }
    coda.reverse () ;
}

function controlloToccoBordo () {
    if (posSn_x > DIM - 1 || posSn_x < 0 || posSn_y > DIM - 1 || posSn_y < 0) {
        haiperso () ;
    }
}

function haiperso () {
    boolPerso = true ;

    var domanda = confirm  ("HAI PERSO, VUOI RIPROVARE?") ;
    if (domanda == true) {
        window.location.reload () ;
    }
}