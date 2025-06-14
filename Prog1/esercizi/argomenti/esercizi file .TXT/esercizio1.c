#include <stdio.h>
#include <limits.h>

int main()
{
   short a = 10;  //%hd
   unsigned int b = 10; //%u
   long c = 10; //%ld

   printf("\nshort: %hd , unsigned int: %u , long: %ld", a , b , c);
    
    a = a + SHRT_MAX;
    printf("\noverflow short: %hd", a);

    b = b + UINT_MAX;
    printf("\noverflow uint: %u", b);

    c = c - LONG_MIN;
    printf("\noverflow long: %ld", c);




    
 



}

