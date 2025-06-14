#include <stdio.h>
#include <math.h>

int massimo(int x, int y) {
    int max;
    if (x < y) {
        max = y;
    } else {
        max = x;
    }
    return max;
}

float media(int x, int y) {
    return (float)(x + y) / 2.0;
}

int main() 
{
    int x, y;

    printf("\ninserisci un numero intero: ");
    scanf("%d", &x);

    printf("\ninserisci un numero intero: ");
    scanf("%d", &y);
    
    int somma = x + y;
    float avg = media(x, y);
    int max = massimo(x, y);
    printf("\nSomma: %d", somma);
    printf("\nMedia: %.2f", avg);
    printf("\nMassimo: %d", max);
}
