#include <stdio.h> 

int main(int argc , char * argv[])
{
    printf("\nnumero di parametri passati: %d", argc);
    
    for(int i = 0; i < argc - 1; i++)
    {
        printf("argc: [%d]: %s\n", i, argv[i]);
    }
    return 0;
}