#include <stdio.h>

static inline int esp(int base , int esponente)
{
    if(esponente <= 0)
    {
        return 1;
    }
    else
    {
        return base * esp(base , esponente - 1);
    }

}




int main()
{
    int base;
    int esponente;

    printf("\nInserisci la base: ");
    scanf("%d", &base);
    printf("\nInserisci l'esponente: ");
    scanf("%d", &esponente);

    printf("\nIl risultato di %d elevato a %d è: %d", base, esponente, esp(base, esponente));

}