"use strict"
const DIM = 3 ;     //dimensione della tabella di gioco

var campo ;     //vettore del campo da gioco

var giocatore = 1 ;

var vinto = false ;

function avvia () {
    disegnaCampo () ;
    initMatrice () ;
}

function initMatrice() {
    campo = new Array(DIM) ;

    for (let x = 0; x < DIM; x++) {
        campo[x] = new Array(DIM) ;
    }

    for (let x = 0; x < DIM; x++) {
        for (let y = 0; y < DIM; y++) {
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

    for (var x = 0; x < DIM; x++) {
        riga = document.createElement ("tr") ;
        tabella.appendChild (riga) ;

        for (var y = 0; y < DIM; y++) {
            cella = document.createElement ("td") ;
            cella.style.width = "170px" ;
            cella.style.height = "170px" ;
            
            riga.appendChild (cella) ;

            bottone = document.createElement ("button") ;
            bottone.id = "btn_" + x + "_" + y ;
            bottone.style.width = "170px" ;
            bottone.style.height = "170px" ;
            bottone.style.fontSize = "100" ;

            cella.appendChild (bottone) ;

            bottone.setAttribute ("OnClick", "disegnaLettera (this);") ;
        }
    }
}

function disegnaLettera (bottone) {
    var vettore = bottone.id.split ("_") ;
    if (giocatore == 1) {
        if (campo[vettore[1]][vettore[2]] == 0) {
            bottone.innerHTML = "X" ;
        
            campo [vettore[1]][vettore[2]] = giocatore ;

            giocatore = 2 ;
        }
        
    } else {
        if (campo[vettore[1]][vettore[2]] == 0) {
            bottone.innerHTML = "O" ;
            
            campo [vettore[1]][vettore[2]] = giocatore ;

            giocatore = 1 ;
        }
    }

    controlloTris () ;
    if (!vinto) {
        controlloPari () ;
    }
}

function controlloTris () {
    for (var t = 1 ; t < 3; t++) {
        for (var x = 0; x < DIM; x++) {
            if (campo[x][0] == t && campo[x][1] == t && campo[x][2] == t) {
                haivinto (t) ;
            }
            if (campo[0][x] == t && campo[1][x] == t && campo[2][x] == t) {
                haivinto (t) ;
            }
            
        }
        if (campo[0][0] == t && campo[1][1] == t && campo[2][2] == t) {
            haivinto (t) ;
        }
        if (campo[0][2] == t && campo [1][1] == t && campo [2][0] == t) {
            haivinto (t) ;
        }
    }
}

function controlloPari () {
    var k = 0 ;
    for (var x = 0; x < DIM; x++) {
        for (var y = 0; y < DIM; y++) {
            if (campo[x][y] == 0) {
                k++ ;
            }
        }
    }
    if (k == 0) {
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