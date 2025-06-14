#include <stdio.h>
#include <math.h>

int main()
{
 double a , b , c;

 printf("\ninserisci un numero intero o decimale: ");
 scanf("%lf", &a);

 
 printf("\ninserisci un numero intero o decimale: ");
 scanf("%lf", &b);

 
 printf("\ninserisci un numero intero o decimale: ");
 scanf("%lf", &c);
    
    a = round(a);
    
    b = round(b);
    
    c = round(c);

    printf("\n%d \n %d \n %d", (int)a , (int)b , (int)c);

}