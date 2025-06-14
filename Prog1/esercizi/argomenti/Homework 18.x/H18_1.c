#include <stdio.h>

static inline int fattoriale(int n)
{
    int fattoriale = 1;
    for(int i = n; i >= 1; i--)
    {
        fattoriale *= i;
    }

    return fattoriale;
}


int main()
{
    int n;
    printf("inserisci un numero: ");
    scanf("%d", &n);

    printf("\n%d ", fattoriale(n));

}
    