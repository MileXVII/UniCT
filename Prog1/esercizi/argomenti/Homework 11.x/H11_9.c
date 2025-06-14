#include <stdio.h>
#include <stdlib.h>

int main()
{
    int persone, scelta;
    do
    {
        printf("\ninserisci un numero compreso tra 2 e 16:");
        scanf("%d", &persone);
    } while (persone < 2 || persone > 16);

    do
    {
        printf("\nci sono diabetici tra i commensali?\n 1: si ,\n0: no\n");
        scanf("%d", &scelta);
    } while (scelta < 0 || scelta > 1);

    if (persone >= 2 && persone <= 4)
    {
        if (scelta == 0)
        {
            printf("\n0.3kg di farina, 4 uova, 0.1kg di zucchero.");
        }
        else
        {
            printf("\n0.3kg di farina, 4 uova, 0.067kg di fruttosio.");
        }
    }
    else if (persone >= 5 && persone <= 8)
    {
        if (scelta == 0)
        {
            printf("\n0.75kg di farina, 10 uova, 0.25kg di zucchero.");
        }
        else
        {
            printf("\n0.75kg di farina, 10 uova, 0.167kg di fruttosio.");
        }
    }
    else if (persone >= 9 && persone <= 16)
    {
        if (scelta == 0)
        {
            printf("\n1.05kg di farina, 14 uova, 0.35kg di zucchero.");
        }
        else
        {
            printf("\n1.05kg di farina, 14 uova, 0.233kg di fruttosio.");
        }
    }

    return 0;
}