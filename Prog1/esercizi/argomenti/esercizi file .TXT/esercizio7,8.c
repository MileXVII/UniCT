#include <limits.h>
#include <stdio.h>

int main()
{
    long long x = LONG_LONG_MAX;
    long long y = LONG_LONG_MIN;

    printf("\n %lld , %lld ", x , y);

    long a = sizeof(long);
    long long b = sizeof(long long);

    printf("\n %lld , %lld ", a , b);



}