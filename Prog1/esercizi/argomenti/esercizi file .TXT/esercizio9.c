/* 9) Calcolare e stampare il valore delle seguenti espressioni in VIRGOLA MOBILE
   a) sin^2(x) + cos^2(y), x e y variabili con valore a piacere
   b) definire tre variabili in virgola mobile che rappresentano 
   la misura di due cateti di un triangolo rettangolo. Calcolare 
   l'ipotenusa del triangolo; 
   c) Dato il valore del raggio di un cerchio, calcolare circonferenza e 
   area del cerchio; usare la costante M_PI definita nel file header math.h (non fa parte della libreria standard ma molte "extensioni" la introducono)
   d) (2+3)/2 * 7/4 + 8.8. Impiegare eventuali espressioni di type-cast, senza cambiare i letterali, al fine di ottenere un risultato senza alcuna perdita di informazioni;  
   e) Sia x un numero in virgola mobile a piacere. Stampare il risultato dell'espressione x/0 - x/0; 
   f) e, e^100, e^300, e^400; 
   g) sia x un valore in virgola mobile, x<1. Sia y un valore in virgola mobile, y>1. Stampare x^10, x^100, x^300, y^10, y^100, y^300. */

   #include <stdio.h>
   #include <math.h>

   #define M_PI 3.14159265358979323846
   #define M_E 2.718281828459045

   int main()
   {
     double x = 2;
     double y = 4;

     double result;

     result = (pow(sin(x), 2)) + (pow(cos(y), 2)); //result = (sin(x) * sin(x)) + (cos(y) * cos(y));
     printf("\nresult: %lf", result);

     double cat1 = 2;
     double cat2 = 4;
     double ipt;

     ipt = sqrt((pow(cat1, 2)) + (pow(cat2, 2))); //sqrt((cat1 * cat1) + (cat2 * cat2));
     printf("\nipotenusa: %lf", ipt);

     double raggio = 2;
     double area;
     double circonferenza;
    
    circonferenza = 2 * M_PI * raggio;
    area = M_PI * pow(raggio, 2);

    printf("\ncirconferenza: %lf , area: %lf", circonferenza , area);

    double res;
    res = ((2.0+3.0)/2.0) * ((7.0/4.0) + 8.8);
    printf("Il risultato è: %.2f\n", res);

    double ris;
    ris = (x/0 - x/0);
    printf("\nrisultato: %lf", ris);

    double e = M_E; 
    double e_100 = exp(100); 
    double e_300 = exp(300); 
    double e_400 = exp(400); 
    printf("Valore di e: %.15f\n , Valore di e^100: %.15e , Valore di e^300: %.15e\n , Valore di e^400: %.15e\n ", e , e_100 , e_300 , e_400); 
    
      double x = -1;
      double y = 2;

        double x_10 = pow(x, 10);
        double x_100 = pow(x, 100);
        double x_300 = pow(x, 300);
        double y_10 = pow(y, 10);
        double y_100 = pow(y, 100);
        double y_300 = pow(y, 300);

        printf("x^10 = %.15e\n", x_10);
        printf("x^100 = %.15e\n", x_100);
        printf("x^300 = %.15e\n", x_300); 
        printf("y^10 = %.15e\n", y_10);
        printf("y^100 = %.15e\n", y_100);
        printf("y^300 = %.15e\n", y_300);

       
   }