#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    double D[9];
    int A[9];
    int i;

    int *ptr_A = A;
    double *ptr_D = D;

    for(int i = 0;i< 9;i++)
    {
        D[i] = 1.25 + ((double)rand() / RAND_MAX) * (90 - 1.25);
    }

      for(int i = 0;i< 9;i++)
    {
        A[i] = 10 + (rand() % (50 - 10 + 1));
    }

    printf("array di int:");

    for(int i = 0; i < 9; i++)
    {   
        printf("\ncontenuto della casella: %d;", A[i] ); 
        
        if(i % 2 == 0)
        {
            printf(" cella di memoria della casella: %p." , (ptr_A + i)); //contenuto della casella via array
        }
        
    }

    printf("\n\n");
    printf("array di double:");
      for(int i = 0; i < 9; i++)
    {
        printf("\ncontenuto della casella: %lf;", D[i] ); 
        
        if(i % 2 == 1)
        {
            printf(" cella di memoria della casella: %p." , *(ptr_D + i)); //contenuto della casella via puntatore
        }
        
    }

}