#include <stdio.h>

static int fibonacci(int n)
{
    int n1 = 1; int n2 = 1; int n3;

    
    printf("\n%d", n1);   
    printf("\n%d", n2);

    for(int i = 0; i < n; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("\n%d ", n3);
    }

    
}

int main()
{
    int n;

    printf("quanti numeri della sequenza di fibonacci vuoi stampare?");
    scanf("%d", &n);

    fibonacci(n);
}