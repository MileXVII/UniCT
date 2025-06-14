#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char nome[100];
    char cognome[100];

    printf("\ninserisci il tuo nome: ");
    scanf("%s", nome);

    
    printf("\ninserisci il tuo cognome: ");
    scanf("%s", cognome);

    char nominativo[200];

    sprintf(nominativo, "\nnome: %s; cognome: %s",nome, cognome); 
    printf("\n%s", nominativo);

    strcpy(nominativo, nome);       // Copia il nome
    strcat(nominativo, ";");        // Aggiungi il separatore ';'
    strcat(nominativo, cognome);    // Copia il cognome

    printf("\n%s", nominativo);

}