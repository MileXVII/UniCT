#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    do{
        printf("scegli un numero di lanci da far fare al dado:");
        scanf("%d", &n);
    }while(n<1);

    srand(time(NULL));

    for(int i=0;i<n;i++)
    {
        int res;
        int res1;
        res = rand()%6+1;
        res1 = rand()%6+1;
        printf("  %d;  %d;\n", res, res1);
    }



}
