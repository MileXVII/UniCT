#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
        double N,M;
        do
        {
            printf("\ninserisci un numero N: ");
            scanf("%lf",&N);
        } while (N<=1);
        
        do
        {
            printf("\ninserisci un numero M: ");
            scanf("%lf",&M);
        } while (M<=1);
        
        int n = round((int)N);
        int m = round((int)M);

        double array[n][m];

        srand((unsigned int)time(NULL));
        
        for(int i = 0; i<n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                array[i][j] = 1.0 + (10.0 - 1.0) * ((double)rand() / RAND_MAX);
            }
        }
         for (int i = 0; i < n; i++) 
         {
        for (int j = 0; j < m; j++) 
        {
            printf(" %8.2f ", array[i][j]);
        }
         }
        double num = 1.0 + (10.0 - 1.0) * ((double)rand() / RAND_MAX);
        
        for (int i = 0; i < n; i++) 
         {
        for (int j = 0; j < m; j++) 
        {
            array[i][j] = array[i][j] * num;
        }
         }

        printf("\necco il risultato della matrice moltiplicata per %lf\n",num);
        for (int i = 0; i < n; i++) 
         {
        for (int j = 0; j < m; j++) 
        {
            printf(" %8.2f ", array[i][j]);
        }
         }

         n = (n < m) ? n : m;
         double array2[n][n];

        for(int i = 0; i<n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                array2[i][j] = array[i][j]; 
            }
        }

        printf("\ninizializzo una nuova matrice NxN con N il numero piu piccolo tra N ed M precedentemente utilizzato per la matrice NxM");
        printf("\nmatrice creata: \n");
        for (int i = 0; i < n; i++) 
         {
        for (int j = 0; j < n; j++) 
        {

            printf(" %8.2f ", array2[i][j]);
        }
         }
        
}