#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int a;
    int b;
    double alpha;
    double beta;

}parametri;

int readInput(parametri *ptr);
double **allocMatrix(parametri *ptr);
void freeMatrix(double **M, double **M1 , parametri *ptr);
void fillMatrix(double **M , parametri *ptr);
double **transposeMatrix(double **M, parametri *ptr);
void printMatrix(double **M, parametri *ptr);


int main(int argc , char *argv[])
{
    srand(time(NULL));

    if(argc != 5)
    {
        printf("\nErrore: devi passare 4 argomenti.");
        return 1;
    }

    parametri *ptr = malloc(sizeof(parametri));

    if (!ptr) {
        printf("\nErrore nell'allocazione della memoria.\n");
        return 1;
    }

    ptr->a = atoi(argv[1]);
    ptr->b = atoi(argv[2]);
    ptr->alpha = atof(argv[3]);
    ptr->beta = atof(argv[4]);

    if (readInput(ptr)) {
        free(ptr);
        return 1;
    }

    double **M = allocMatrix(ptr);
    fillMatrix(M , ptr);

    printf("\n\vpassaggio da matrice 'M' a trasposta di 'M'...\n\v");

    double **M1 = transposeMatrix(M , ptr);


    freeMatrix(M , M1 ,ptr);
    free(ptr);
}

int readInput(parametri *ptr)
{
    if(ptr->a >= 5 && ptr->a <= 20 && ptr->b >= 5 && ptr->b <= 20)
    {
        if(ptr->alpha >= 10 && ptr->alpha <= 20)
        {
            if(ptr->beta >= 1 && ptr->beta <= 5)
            {
                printf("\nInserimento avvenuto!");
                return 0;
            }
            else
            {
                printf("\nErrore: beta deve essere compreso tra 1 e 5.");
                return 1;
            }
        }
        else
        {
            printf("\nErrore: alpha deve essere compreso tra 10 e 20.");
            return 1;
        }
    }
    else
    {
        printf("\nErrore: a e b devono essere compresi tra 5 e 30");
        return 1;
    }
}

double **allocMatrix(parametri *ptr)
{
    printf("\nAllocazione delle matrice... ");
    double **M = (double**)malloc(ptr->a * sizeof(double *));
    
    if (M == NULL) {
        printf("Errore nell'allocazione dell'array di righe!\n");
        return NULL;
    }

    for(int i = 0; i < ptr->a; i++)
    {
        M[i] = (double *)malloc(ptr->b * sizeof(double));

        if (M[i] == NULL) 
        {
            printf("Errore nell'allocazione della riga %d!\n", i);
            for (int j = 0; j < i; j++) 
            {
                free(M[j]);
            }

            free(M);
            return NULL;
        }
    }

    return M;

}

void freeMatrix(double **M, double **M1 , parametri *ptr)
{
    for(int i = 0; i < ptr->a ; i++)
    {
            free(M[i]);
    }
    for(int i = 0; i < ptr->b ; i++)
    {
            free(M1[i]);
    }
}   

void fillMatrix(double **M , parametri *ptr)
{
    
    printf("\n riempimento della Matrice...");
    double p = (double)rand() / RAND_MAX;
    
        for (int i = 0; i < ptr->a; i++) {
        for (int j = 0; j < ptr->b; j++) {
            if (p > 0.2) {
                
                M[i][j] = ((double)rand() / RAND_MAX) * ((ptr->alpha + ptr->beta) - (ptr->alpha - ptr->beta)) + (ptr->alpha - ptr->beta);
            } else {
                
                M[i][j] = 0.0; 
            }
        }
    }

    printMatrix(M , ptr);
    
}

double **transposeMatrix(double **M, parametri *ptr)
{
    
    printf("\n Allocazione della trasposta...");
    double **M1 = (double**)malloc(ptr->b * sizeof(double *));
    if (M1 == NULL) {
        printf("Errore nell'allocazione della matrice trasposta!\n");
        return NULL;
    }

    for (int i = 0; i < ptr->b; i++) {
        M1[i] = (double *)malloc(ptr->a * sizeof(double));
        if (M1[i] == NULL) {
            printf("Errore nell'allocazione della riga %d della matrice trasposta!\n", i);
            for (int j = 0; j < i; j++) {
                free(M1[j]);
            }
            free(M1);
            return NULL;
        }
    }

    for (int i = 0; i < ptr->a; i++) {
        for (int j = 0; j < ptr->b; j++) {
            M1[j][i] = M[i][j]; 
        }
    }

    double tmp = ptr->a;
    ptr->a = ptr->b;
    ptr->b = tmp;

    printMatrix(M1 , ptr);
    return M1;
}

void printMatrix(double **M, parametri *ptr)
{
    
    printf("\n Stampa della matrice...");
    for (int i = 0; i < ptr->a; i++) {
        for (int j = 0; j < ptr->b; j++) {

            if(M[i][j] == 0.0)
            {
                printf("\n| N |");
            }
            else
            {
                printf("\n| %02f |", M[i][j]);
            }
        }
    }
}