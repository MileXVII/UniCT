#include <stdio.h>
#include <math.h>
#include <float.h>

int main()
{
    float x;
    double y;

    x = 10882000;
    y = x * (1.23456 * pow(10, 100)); 

  printf("\n float x: %.6e , double y = %.6E", x, y);

  x = x * y;

  printf("\noverflow di x: %f", x );

  y = y * DBL_MAX;

  printf("\noverflow di y: %f", y );
}