#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
    {

        char s1[100]; char s2[100]; char s3[100];

        printf("\ninserisci un numero di tipo double: \n");
        scanf("%s", &s1);

        printf("\ninserisci un numero di tipo double: \n");
        scanf("%s",&s2);

        printf("\ninserisci un numero di tipo double: \n");
        scanf("%s",&s3);

        double d1,d2,d3;

        d1 = atof(s1); // converte in double
        printf("\nValore double con atof: %lf\n", d1);    

        if (sscanf(s2, "%lf", &d2) == 1) {
        printf("\nValore double con sscanf: %lf\n", d2);
        } else {
        printf("\nErrore durante la lettura con sscanf\n");
        }
        
        char *val1;
        d3 = strtof(s3, &val1); // converte in double
        printf("\nValore double con strtof: %lf\n", d3);    
        










        return 0;
    }