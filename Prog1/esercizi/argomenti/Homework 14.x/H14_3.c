#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int N = 200;
    double V[N];

    double *ptr = N;
    const double *const ptr1 = V;
    int i;

        srand(time(NULL));

    for(i = 0; i < N; i++)
    {
        V[i] = 10 + (double)rand() / RAND_MAX * (50 - 10);
    }

    for(i = 0; i < N; i++)
    {
        if(i % 2 != 0 && i % 3 != 0)
        {
            printf("\n contenuto casella: %.2lf", *(ptr + i));      
        }
        else
        {
             V[i] = 100 + (double)rand() / RAND_MAX * (200 - 100);
            printf("\n nuovo contenuto casella: %.2lf", V[i]);
        }
    }
    return 0;
}