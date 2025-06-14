#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void function(int array[20][20], double y)
{
    int c; 
    int contatore = 0;  
    int k;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            c = 0; 
            for (k = 0; k < 20; k++) 
            {
                c += array[k][j]; //c = arrat[i][j] + 1  
            }
            if ((double)c / 20 <= y)  
            {
                contatore++;
            }
        }
    }
    printf("\nLe colonne della matrice che soddisfano il requisito (la media aritmetica sia <= %.1f) sono: %d\n", y, contatore);
}

int main()
{
    srand(time(NULL));
    double y = 49.5;
    int array[20][20];

    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            array[i][j] = rand() % 100;  // Genera numeri casuali tra 0 e 99
        }
    }

    function(array, y);

    return 0;
}
