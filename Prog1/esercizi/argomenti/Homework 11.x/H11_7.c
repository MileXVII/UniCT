#include <stdio.h>
#include <math.h>

int main()
{
   double cat1;
   double cat2;
   double ipotenusa;

   printf("\ninserisci il cateto 1:");
   scanf("%lf", &cat1);
     
   printf("\ninserisci il cateto 2:");
   scanf("%lf", &cat2);

   ipotenusa = sqrt(pow(cat1, 2) + pow(cat2, 2));

   printf("\nl'ipotenusa è: %lf", ipotenusa);
   

}