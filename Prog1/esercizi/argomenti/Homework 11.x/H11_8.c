#include <stdio.h>
#include <math.h>

#define M_PI 3.141592653589793238462643383279502884197169399375105

int main()
{
   double raggio;
   double circonferenza;

   printf("\ninserisci il raggio del cerchio");
   scanf("%lf", &raggio);

   circonferenza = 2 * M_PI * raggio;

   printf("\nla circonferenza è: %lf", circonferenza);



   return 0;
}