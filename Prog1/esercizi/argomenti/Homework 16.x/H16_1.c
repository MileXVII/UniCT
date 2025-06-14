#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

void function(char ***M ,int n , int m )
{       

    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < m; j++)
        {
            printf("\ninserisci una parola in: [%d , %d]", i , j);
            M[i][j] = (char *)malloc(MAX_STR_LEN * sizeof(char)); // supponendo una lunghezza massima di 100 caratteri
            scanf("%s", M[i][j]);
        }
    }

       int contatore[n][m];
       for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        contatore[i][j] = 0;
    }
}
    
    for(int i = 0;i < n; i++) //ROWS
    {
        for(int j = 0; j < m; j++) //COLS
        {   
            if(strlen(M[i][j]) % 2 == 0)
            {
                int is_palindrome = 1; // Assume che sia palindromo
                    for (int k = 0; k < (strlen(M[i][j]) / 2); k++) {
                        if (M[i][j][k] != M[i][j][strlen(M[i][j]) - 1 - k]) 
                        {
                            is_palindrome = 0; // Non è un palindromo
                            break;
                         }
                        }
                            if (is_palindrome) 
                            {
                                contatore[i][j] = 1;
                            }
            }
            
        }
    }

    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < m; j++)
        {
            if(contatore[i][j])
            {
                printf("%s\n", M[i][j]);
            }
        }
    }



}

int main()
{
    int n,m;
    char ***M;

    printf("\nquando vuoi sia grande l'array? (n , m): ");
    scanf("%d %d", &n, &m);

    M = (char ***)malloc(n * sizeof(char **));
    
        if (M == NULL) 
        {
            printf("Errore di allocazione memoria.\n");
            exit(1);
        }

        for (int i = 0; i < n; i++) 
            {
            M[i] = (char **)malloc(m * sizeof(char *));
            }

    function(M , n , m);


    for (int i = 0; i < n; i++) {  // Itera sulle righe
    for (int j = 0; j < m; j++) {  // Itera sulle colonne
        free(M[i][j]);  // Libera la memoria per ogni stringa
    }
    free(M[i]);  // Libera la memoria per ogni riga
}
free(M);  // Libera la memoria per il puntatore principale

    return 0;

}