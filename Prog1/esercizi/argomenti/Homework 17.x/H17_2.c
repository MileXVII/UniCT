#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, num1, num2;
    srand(time(NULL));

    // Prima stringa
    do
    {
        printf("Inserisci un numero compreso tra 10 e 20: ");
        scanf("%d", &num);
    } while(num < 10 || num > 20);

    char str[num + 1];  // +1 per il terminatore null '\0'
    for (int i = 0; i < num; i++)
    {
        str[i] = 'a' + rand() % 26;
    }
    str[num] = '\0';  // Terminazione della stringa

    // Seconda stringa
    do
    {
        printf("Inserisci un numero compreso tra 10 e 20: ");
        scanf("%d", &num1);
    } while(num1 < 10 || num1 > 20);

    char str1[num1 + 1];  // +1 per il terminatore null '\0'
    for (int i = 0; i < num1; i++)
    {
        str1[i] = 'a' + rand() % 26;
    }
    str1[num1] = '\0';  // Terminazione della stringa

    // Terza stringa
    do
    {
        printf("Inserisci un numero compreso tra 10 e 20: ");
        scanf("%d", &num2);
    } while(num2 < 10 || num2 > 20);

    char str2[num2 + 1];  // +1 per il terminatore null '\0'
    for (int i = 0; i < num2; i++)
    {
        str2[i] = 'a' + rand() % 26;
    }
    str2[num2] = '\0';  // Terminazione della stringa

    // Ordinamento delle stringhe
    char *strings[] = {str, str1, str2};

    // Confronto e ordinamento usando strcmp
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                // Scambio dei puntatori
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }

    // Stampare le stringhe ordinate
    printf("\nLe stringhe ordinate in ordine crescente sono:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}
