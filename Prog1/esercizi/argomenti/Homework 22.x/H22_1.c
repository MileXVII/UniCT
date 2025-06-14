#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 10


int function_write (double A[N][M])
{

    FILE *file_handle = fopen("matrice.txt" , "w");

    if(file_handle == NULL)
    {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }

    fprintf(file_handle , "%d %d \n" ,N , M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            fprintf(file_handle, "%lf " , A[i][j]);
        }
    }
    printf("\nmatrice 'A' scritta correttamente all'interno del file 'matrice.txt'");


    fclose(file_handle);
    printf("\nfile chiuso");
}



int function_append (double A[N][M])
{

    FILE *file_handle = fopen("matrice.txt" , "a+");

    if(file_handle == NULL)
    {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }

    fprintf(file_handle , "\n%d %d \n" ,M , N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            fprintf(file_handle, "%lf " , A[i][j]);
        }
    }
    printf("\ntrasposta 'F' della matrice 'A' scritta correttamente all'interno del file 'matrice.txt'");


    fclose(file_handle);
    printf("\nfile chiuso");
}

int function_save(double A[N][M])
{
    FILE *file_handle = fopen("matrice.txt" , "r");

    if(file_handle == NULL)
    {
        printf("Errore nell'apertura del file!\n");
        return 1;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            fscanf(file_handle , "%lf ", &A[i][j]);
        }
    }
    printf("\nmatrice salvata correttamente in 'matrice.txt'");
    
    fclose(file_handle);
    printf("\nfile chiuso");

}

void trasposta(double A[N][M])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            A[i][j] = A[j][i];  // Assigning directly from A[j][i] to A[i][j]
        }
    }
}


int main()
{
    srand(time(NULL));

    double A[N][M];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            A[i][j] = ((rand() / (double)RAND_MAX) * 99) + 1;
        }
    }

    function_write(A);

    function_save(A);

    trasposta(A); // non funziona bene

    function_append(A);

}