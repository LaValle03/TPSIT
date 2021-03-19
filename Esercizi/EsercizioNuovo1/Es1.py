def forward(x):
    print(f"Il robot si nuove in avanti di {x} metri")

def backward(x):
    print(f"Il robot si muove indietro di {x} metri")

def left(x):
    print(f"Il robot si muove a sinistra di {x} metri")

def right(x):
    print(f"Il robot si muove a destra di {x} metri")

def main():
    lista_tupla = [("f", 50), ("f", 30), ("r", 90), ("f", 10), ("l", 60)]
    dizionario_funzioni = {"f": forward, "b": backward, "r": right, "l": left}

    for movimento, valore in lista_tupla:
        dizionario_funzioni[movimento](valore)
        

if __name__=="__main__":
    main()