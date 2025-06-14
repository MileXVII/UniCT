#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    int n;
    do{
    printf("quanto vuoi sia grande l'array?\n");
    scanf("%d", &n);
    }while(n<5);

    char s[50];

    for(int i = 0; i<n;i++)
    {
        s[i] = rand() % 26 + 'a';
        printf(" %c", s[i]);
    }

    char str[] = "my_string";

    printf("\nla stringa generata e' %s", str);
    printf("\nla stringa è lunga: %d\n", strlen(str));

    const char *str1 = "my_string";

    printf("\nla stringa generata e' %s", str1);
    printf("\nla stringa è lunga: %d\n", strlen(str1));
}