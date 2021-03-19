#include <stdio.h>
#include <stdlib.h>


struct El
{
    int valore;
    struct El *next;
};


int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; /* fa puntare la lista a niente, svuota il suo contenuto */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* se la lista non punta a niente */
            {
                /* Usando la malloc, alloco El in memoria. Assegno poi a l'indirizzo puntato la lista LISTA*/

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else /* se la lista non è vuota, e punta a qualcosa */
            {
                /* viene allocata la lista successiva in memoria. Assegno poi a l'indirizzo puntato la lista L */

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  /* viene inserito il numero naturale all'interno della lista */
            l->next = NULL; /* viene svuotata la lista successiva, non punta a niente */
        }
    } while (n >= 0);

    l = lista; /* viene assegnato all'offset la lista e poi viene stampata finchè non arriva a una cella vuota */
    printf("numeri inseriti: ");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* viene incrementato l per farlo puntare alla prossima lista e poi viene stampato il suo contenuto */
    }
    printf("\n");
    return 0;
}