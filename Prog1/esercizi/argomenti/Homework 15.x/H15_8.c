#include <stdio.h>
#include <math.h>

void funzione(double A[][100], int n, double z)
{
    double dx = 0;  // diagonale secondaria
    int contatore = 0;
    
    // Calcolo della diagonale secondaria
    for(int i = 0; i < n; i++)
    {
        dx += A[i][n - (i + 1)];
    }
    
    printf("La diagonale secondaria: %lf\n", dx);  // stampa la diagonale secondaria
    
    // Stampare la matrice
    printf("Matrice inserita:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%lf ", A[i][j]);  // stampa la matrice dopo ogni input
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++)
    {
        double colonna = 0;
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);  // input degli elementi della matrice
        }
    }

    for(int i = 0; i < n; i++)
    {
        double colonna = 0;
        for(int j = 0; j < n; j++)
        {
            colonna += A[j][n - (i + 1)];  // somma gli elementi di ciascuna colonna "invertita"
        }
        double media_colonna = colonna / n;  // calcolo la media di ciascuna colonna
        printf("Somma colonna %d: %lf, Media colonna %d: %lf\n", i, colonna, i, media_colonna);  // stampa la somma e la media delle colonne
        
        if(fabs(dx - media_colonna) < z)
        {
            contatore++;
        }
    }

    printf("Le colonne che soddisfano la condizione sono: %d\n", contatore);
}

int main()
{
    int n;
    double z;
    
    printf("Quanto vuoi sia grande l'array: ");
    scanf("%d", &n);

    double A[n][n];  // Dichiarazione della matrice statica

    printf("Inserisci un numero double per la condizione: ");
    scanf("%lf", &z);

    printf("Inserisci gli elementi della matrice (n x n):\n");
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);  // Input degli elementi della matrice
        }
    }

    funzione(A, n, z);  // Passo la matrice alla funzione

    return 0;
}
