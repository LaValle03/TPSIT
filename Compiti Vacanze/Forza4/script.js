"use strict"
const ALTEZZA = 6 ;
const LUNGHEZZA = 7 ;

var giocatore = 1 ;

var vinto = false ;

var campo ;

const ROSSO = "rgb(255, 0, 0)";
const BLU = "rgb(0, 0, 255)";

function avvia () {
    disegnaCampo () ;
    initMatrice () ;
}

function initMatrice() {
    campo = new Array(LUNGHEZZA) ;

    for (let x = 0; x < LUNGHEZZA; x++) {
        campo[x] = new Array(ALTEZZA) ;
    }

    for (let x = 0; x < LUNGHEZZA; x++) {
        for (let y = 0; y < ALTEZZA; y++) {
            campo[x][y] = 0 ;
        }
    }
}

function disegnaCampo () {
    var refBody = document.getElementsByTagName ("body") [0] ;
    var tabella = document.createElement ("table") ;

    var riga, bottone, cella ;

    refBody.appendChild (tabella) ;

    tabella.border = "1" ;
    tabella.align = "center" ;

    for (var x = 0; x < ALTEZZA; x++) {
        riga = document.createElement ("tr") ;
        tabella.appendChild (riga) ;

        for (var y = 0; y < LUNGHEZZA; y++) {
            cella = document.createElement ("td") ;
            cella.style.width = "80px" ;
            cella.style.height = "80px" ;
            
            riga.appendChild (cella) ;

            bottone = document.createElement ("button") ;
            bottone.id = "btn_" + y + "_" + x ;
            bottone.style.width = "80px" ;
            bottone.style.height = "80px" ;

            cella.appendChild (bottone) ;

            bottone.setAttribute ("OnClick", "mettiMoneta (this);") ;
        }
    }
}

function mettiMoneta (bottone) {
    var vettore = bottone.id.split ("_") ;
    //console.log ([vettore[1]] + vettore[2]) ;

    for (var k = ALTEZZA - 1; k >= 0; k--) {
        if (campo[vettore[1]][k] == 0) {
            campo[vettore[1]][k] = giocatore ;

                if (giocatore == 1) {
                    document.getElementById("btn_" + vettore[1] + "_" + k).style.backgroundColor = ROSSO;
                    giocatore = 2 ;
                } else {
                    document.getElementById("btn_" + vettore[1] + "_" + k).style.backgroundColor = BLU;
                    giocatore = 1 ;
                }
            k = -1 ;
        }
    }

    controlloVincita () ; 
    if (!vinto) {
        controlloPari () ;
    }
}

function controlloVincita () {
    var j = 0 ;

    for (var t = 1; t < 3; t++) {                   //controllo vincita verticale
        for (var y = 0; y < ALTEZZA; y++) {
            for (var x = 0; x < LUNGHEZZA; x++) {
                if (campo[x][y] == t) {
                    j++ ;

                    if (j == 4) {
                        y = ALTEZZA ;
                        haivinto (t) ;
                    }
                } else {
                    j = 0 ;
                }
            }
            j = 0 ;
        }
        j = 0 ;
        y = 0 ;
        x = 0 ;

        for (var x = 0; x < LUNGHEZZA; x++) {       //controllo vincita orizzontale
            for (var y = 0; y < ALTEZZA; y++) {
                if (campo[x][y] == t) {
                    j++ ;

                    if (j == 4) {
                        x = LUNGHEZZA ;
                        haivinto (t) ;
                    }
                } else {
                    j = 0 ;
                }
            }
            j = 0 ;
        }

        y = 0 ;
        x = 0 ;
        j = 0 ;
        var k = 0 ;

        for (var x = 0; x < 4; x++) {           //controllo vincita obliqua
            for (var y = 0; y < 3; y++) {
                for (var j = 0; j < 4; j++) {
                    if (campo[x + j][y + j] == t) {
                        k++ ;
                        if (k == 4) {
                            haivinto (t) ;
                            y = 4 ;
                        }
                    } else {
                        k = 0 ;
                    }
                }
            }
            k = 0 ;
        }

        for (var x = 3; x < 7; x++) {           //controllo vincita obliqua invertita          
            for (var y = 0; y < 3; y++) {  
                for (var j = 0; j < 4; j++) {  
                    if (campo[x - j][y + j] == t) {  
                        k++ ;
                        console.log (k) ;
                        if (k == 4) {
                            haivinto (t) ;
                            y = 4 ;
                        }
                    } else {
                        k = 0 ;
                    }
                }
            }
            k = 0 ;
        }
    }
}

function controlloPari () {
    var cnt = 0 ;
    for (var x = 0; x < LUNGHEZZA; x++) {
        for (var y = 0; y < ALTEZZA; y++) {
            if (campo[x][y] == 0) {
                cnt++ ;
            }
        }
    }
    if (cnt == 0) {
        parita () ;
    }
}

function haivinto (t) {
    setTimeout(() => { 
        var domanda = confirm ("Il giocatore " + t + " ha vinto. Vuoi riprovare?") ;

        if (domanda) {
            window.location.reload () ;
        }
    }, 1);
    vinto = true ;
}

function parita () {
    setTimeout(() => { 
        var domanda = confirm ("La partita e' finita in parita'. Vuoi riprovare?") ;

        if (domanda) {
            window.location.reload () ;
        }
    }, 1);
}