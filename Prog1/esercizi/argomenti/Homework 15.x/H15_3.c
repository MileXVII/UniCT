#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function(char c[20])
{
    int lunghezza = strlen(c);  
    printf("la lunghezza della stringa e' %d\n", lunghezza - 1);
}

int main()
{
    char c[20];
    printf("inserisci una parola: ");
    scanf("%c", c);

    function(c);

}