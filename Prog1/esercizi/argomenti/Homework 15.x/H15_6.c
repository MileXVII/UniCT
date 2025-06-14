#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void function(int A[] , int B[], int N)
{

        srand(time(NULL));

        int i;
        int c = 0;

        for(i = 0; i < N ; i++)
        {
            while(B[i] != 0)
            {
            if(((double)A[i]/B[i])<1)
            {
                B[i] = A[i];
                A[i] = rand() % (200 - 100 + 1) + 100;
            }else
            {
                if(((double)A[i]/B[i])>1)
                {
                    A[i] = B[i];
                    B[i] = rand() % 100; 
                }else
                {
                    B[i] = A[i];
                    A[i] = 0;
                    c++;
                }
            }
            }
        }
        printf("(A[i]/B[i] = 1: %d volte)\n",c);
}

int main()
{

    int N;
    printf("quanto vuoi sia grande l'array? ");
    scanf("%d", &N);
    int A[N];
    int B[N];

    function(A , B , N);
}