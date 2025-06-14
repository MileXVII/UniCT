#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

bool esercizio1(int A[4][3][3], double w)
{
    for (int i = 0; i < 4; i++)  
    {
        int dxMax = A[i][0][0]; 
        int dxMin = A[i][0][0];
        double dxMedia = 0;

       
        for (int j = 0; j < 3; j++)
        {
            if (A[i][j][3 - j] > dxMax) {
                dxMax = A[i][j][3 - j];  
            }
            if (A[i][j][3 - j] < dxMin) {
                dxMin = A[i][j][3 - j];  
            }
        }


        dxMedia = (dxMax + dxMin) / 2.0;

        if (dxMedia <= w) {
            return true; 
        }
    }

    return false; 
}




int main()
{
    srand(time(NULL));

    int A[4][3][3];

    for(int i = 0; i< 4; i++)
    {
        for(int j = 0; j< 3; j++)
        {
            for(int k = 0; k< 3; k++)
            {
                A[i][j][k] = 1 + rand() % 100;
            }
        }
    }

    double w;

    printf("\nInserisci un numero double: ");
    scanf("%lf", &w);

    if(esercizio1(A , w))
    {
        printf("\ntrue");
    }
    else
    {
        printf("\nfalse");
    }

}