#include <stdio.h>

int main()
{
    double l = 1.1;
    short unsigned b = 2;  
    char c = 'A';

    double *p1 = &l;
    short unsigned *p2 = &b;
    char *p3 = &c;

    //stampo i numeri 
    printf("\ndouble: %.1lf , short unsigned: %hu , char %c", l , b , c);

    //stampo i puntatori
    printf("\npuntatore double: %p , puntatore short unsigned: %p , puntatore char: %p", p1 , p2 , p3);

    //stampo slot memoria
    printf("\npuntatore double: %p , puntatore short unsigned: %p , puntatore char: %p", (void *) p1 , (void * ) p2 , (void *) p3);
}
