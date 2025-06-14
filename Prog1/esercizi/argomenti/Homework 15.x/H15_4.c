#include <stdio.h>
#include <string.h>

void function(const char *s1 , const char *s2)
{   

    int res;
    res = strcmp(s1 , s2);
    if(res < 0)
    {
        printf("%s è minore di %s\n", s1, s2);
    }
    else
    {
        if(res > 0)
        {
            printf("%s è maggiore di %s\n", s1, s2);
        }
        else 
        {
            printf("%s è uguale a %s\n", s1, s2);
        }
        
    }
}

int main()
{
    char s1[20];
    char s2[20];

    printf("iserisci una parola: ");
    scanf("%s", s1);

    printf("\ninserisci una seconda parola :");
    scanf("%s", s2);

    function(s1 , s2);
}