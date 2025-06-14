#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int t;
    printf("Quanti punti vuoi lanciare? ");
    scanf("%d", &t);
    
    int s = 0; // successi

    double array[t][2]; // Contenitore dei numeri generati

    printf("\nI punti casuali generati nel quadrato [-1, 1] x [-1, 1]:\n");
    for (int i = 0; i < t; i++) {
        double x = ((double)rand() / RAND_MAX) * 2 - 1; // Genera numero casuale tra -1 e 1 per x
        double y = ((double)rand() / RAND_MAX) * 2 - 1; // Genera numero casuale tra -1 e 1 per y

        printf("Punto %d: (%.2lf, %.2lf)\n", i + 1, x, y);  // Stampa punto casuale

        if (sqrt(pow(x, 2) + pow(y, 2)) <= 1) {
            array[s][0] = x;  
            array[s][1] = y;  
            s++;
        }
    }

    printf("\nI punti all'interno del cerchio sono:\n");
    for (int i = 0; i < s; i++) {
        printf("Punto %d: (%.2lf, %.2lf)\n", i + 1, array[i][0], array[i][1]);
    }
        
    double PI = 4.0 * (double)s / t;  // Formula Monte Carlo per π
    printf("\nPi greco: %lf\n", PI);
}
