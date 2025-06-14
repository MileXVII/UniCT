#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static int somma(int A[] , int N)
{
    if( N <= 0 )
    {
        return 0;
    }else
    {
        return A[N-1] + somma(A, N-1);
    }

}




int main()
{
    
    srand(time(NULL));
    int N = 10;
    int A[N];

    for(int i = 0; i < N; i++)
    {
        A[i] = 1 + rand() % 10;
    }

    printf("\ninzio debug\n ");
     for(int i = 0; i < N; i++)
    {
        printf("\n%d ", A[i]);
    }
    printf("\nfine debug\n ");
    printf("\nLa somma degli elementi dell'array è: %d", somma(A , N));

}