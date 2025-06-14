#include <stdio.h>
#include <stdlib.h>

void function (short int a , short int b , short unsigned *ptr)
{
        short unsigned res;
        res = (short int)abs((int)(a * b));
        printf("\nrisultato = %hd\n", res);
        *ptr = res;
        printf("\nrisultato puntatore: %hu\n", *ptr);
}

int main()
{
    short int a;
    short int b;
    short unsigned *ptr;
    

    printf("\ninserisci un numero intero: ");
    scanf("%hd ", &a);
    printf("\ninserisci un numero intero: ");
    scanf("%hd ", &b);

    function(a , b , ptr);
}