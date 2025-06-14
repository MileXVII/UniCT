#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void function(int array[][100] , int n)
    {
        int i;
        double dx = 0; //diagonale secondaria
        double dy = 0; //diagonale principale
        double res;

        for(i = 0; i < n; i++)
        {
            dx += array[i][n - i]; //scorro secondaria
            dy += array[i][i];  //scorro principale
        }

        res = fabs((dx/n) - (dy/n));

        printf("%.2lf \n", res);
    }

int main()
{
        int n;

        printf("\nquanto vuoi sia grande l'array? ");
        scanf("%d", &n);

        int array[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                array[i][j] = rand() % 100 + 1;
            }
        }

        function(array , n);
}