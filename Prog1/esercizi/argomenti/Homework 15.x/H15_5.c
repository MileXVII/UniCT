#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void function(char *s1, int lunghezza)
{
    srand(time(NULL));

    int i;
    int vocali = 0;

    for (i = 0; i < lunghezza; i++)
    {
        int a = 'a';
        int z = 'z';
        // Sostituisco ogni casella dell'array di caratteri con lettere casuali da 'a' a 'z'.
        s1[i] = rand() % (z - a + 1) + a;

        // Controllo le vocali nell'array
            if (*(s1 + i) == 'a' || *(s1 + i) == 'e' || *(s1 + i) == 'i' || *(s1 + i) == 'o' || *(s1 + i) == 'u')
            {
                vocali++;
            }
    }

    s1[lunghezza] = '\0';  
    printf("\nLe vocali sono: %d ", vocali);
}

int main()
{
    char s1[100];
    int lunghezza;

    printf("Inserisci una parola: ");
    scanf("%s", s1); 

    lunghezza = strlen(s1); 

    function(s1, lunghezza);


}
