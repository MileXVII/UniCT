#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void function(unsigned int A[][100], short unsigned a, short unsigned b, double z)
{
    srand(time(NULL));
    int i, j;
    unsigned int n;
    unsigned int m = 20;
    double media = 0;
    int contatore = 0;
    
    do{
        printf("inserisci un numero per n: ");
        scanf("%d", &n);
    } while(n <= b);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            A[i][j] = rand() % 100 + 1;
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            media += A[i][j];
        }
    }
    media = media / (n * m);
    printf("La media generale è: %f\n", media);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(j >= a && j <= b && A[i][j] > z)
            {
                contatore++;
            }
        }
    }
    printf("Il numero di elementi che soddisfano la richiesta è: %d\n", contatore);
}

int main()
{   
    unsigned short a, b;
    double z = 20.0;
    
    do{
        printf("inserisci un numero per a: ");
        scanf("%hu", &a);
    } while(a < 0);

    do{
        printf("inserisci un numero per b: ");
        scanf("%hu", &b);
    } while(b <= a);

    unsigned int A[100][100];

    function(A, a, b, z);


}
