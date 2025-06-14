#include <stdio.h>
#include <math.h>

int main()
{   
    double p = 0;
    printf("\ninserisci un numero p:");
    scanf("%lf", &p);

    if(p<1)
    {
        printf("\nerrore");
    }
    else
    {
        int n = (int)round(p);
        int array[n];

        int scelta;
    printf("\ncon quale metodo vuoi stampare il vettore?:");
    printf("\n 0: Ciclo For;");
    printf("\n 1: Ciclo While;");
    printf("\n 2: Ciclo DoWhile.");
    scanf("%d", &scelta);

    int i;
    switch (scelta)
    {
    case 0:
        for(i = 0; i<n; i++)
        {
            printf("\ninserisci un numero da allocare nell'array");
            scanf("%d", &array[i]);
        }
        break;
    case 1:
        while(i<n)
        {
            printf("\ninserisci un numero da allocare nell'array");
            scanf("%d", &array[i]);
            i++;
        }
        break;
    case 2:
        do
        {
            printf("\ninserisci un numero da allocare nell'array");
            scanf("%d", &array[i]);
            i++;
        } while (i<n);
        
        break;
    default:
        printf("\nnon è una scelta valida.");
        break;
    }
    }
}