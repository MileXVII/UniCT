#include <stdio.h>
#include <float.h>

int main()
{
    double y = 2;
    double x = 0.5;

    while (y > DBL_MIN)
    {
        y = y * x;
        printf("\n%E", y);
        if (y == 0.0) break;
    }
    
    y = -3;

     while(y < -DBL_MIN)
    {
        y = y * x;
        printf("\n%E", y);
        if (y == 0.0) break;
    };

}