#ARGOMENTI DI DEFAULT PER LE FUNZIONI

def operazione(x, y, tipo_operazione = "+"):    #valore di default +
    if tipo_operazione == "+":
        return x + y
    elif tipo_operazione == "-":
        return x - y
    elif tipo_operazione == "*":
        return x * y
    elif tipo_operazione == "/":
        return x / y
    else:
        return "ERRORE"


print(operazione(5, 4))         #somma automatica anche senza il terzo parametro
print(operazione(5, 4, "-"))    #sottrazione