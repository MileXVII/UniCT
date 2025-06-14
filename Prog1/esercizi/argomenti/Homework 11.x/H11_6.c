#include <stdio.h>
#include <string.h>

int main() 
{
    char nome[100], cognome[100], duplicati[100] = {0};

    printf("\ninserisci il nome: ");
    scanf("%s", nome);

    printf("\ninserisci il cognome: ");
    scanf("%s", cognome);

    if (strlen(nome) > 1 && strlen(cognome) > 3) {
        printf("\nLa prima lettera del nome è: %c", nome[0]);
        printf("\nL'ultima lettera del nome è: %c", nome[strlen(nome) - 1]);
        printf("\nLa seconda lettera del cognome è: %c, la terza è: %c", cognome[1], cognome[2]);
    } else {
        printf("\nNon ci sono abbastanza lettere nel nome o nel cognome");
    }
    if(nome[0] == cognome[0])
    {
        printf("\nla prima lettera del nome è uguale alla prima lettera del cognome");
    }
        
        printf("\nLe lettere in comune tra nome e cognome sono:\n");
    for (int i = 0; i < strlen(nome); i++) {
        for (int j = 0; j < strlen(cognome); j++) 
        {
            
            if (nome[i] == cognome[j]) 
            {
                int presente = 0;
                for(int k = 0; k<strlen(duplicati); k++)
                {
                    if(duplicati[k]==nome[i])
                    {
                        presente = 1;
                        break;
                    }
                }
                if(!presente)
                {
                    printf("%c", nome[i]);
                    duplicati[strlen(duplicati)] = nome [i];
                }
            }
          
        }
    }
    int conta = 0;
    int contac = 0;
    int contan = 0;
       printf("\nle consontanti nel nome sono: %d , nel cognome sono: %d , in tutto sono: %d", contan , contac , conta);
for (int i = 0; i < strlen(nome); i++) {
        if (nome[i] != 'a' && nome[i] != 'A' &&
            nome[i] != 'e' && nome[i] != 'E' &&
            nome[i] != 'i' && nome[i] != 'I' &&
            nome[i] != 'o' && nome[i] != 'O' &&
            nome[i] != 'u' && nome[i] != 'U') {
            contan++;
        }
    }
    for (int i = 0; i < strlen(cognome); i++) {
        if (cognome[i] != 'a' && cognome[i] != 'A' &&
            cognome[i] != 'e' && cognome[i] != 'E' &&
            cognome[i] != 'i' && cognome[i] != 'I' &&
            cognome[i] != 'o' && cognome[i] != 'O' &&
            cognome[i] != 'u' && cognome[i] != 'U') {
            contac++;
        }
    }

    conta = contac + contan;

    printf("\nLe consonanti nel nome sono: %d, nel cognome sono: %d, in totale sono: %d", contan, contac, conta);

    if(contac == contan)
    {
        printf("\nle consonanti del nome sono uguali di numero a quelle del cognome!");
    }
    return 0;
}
