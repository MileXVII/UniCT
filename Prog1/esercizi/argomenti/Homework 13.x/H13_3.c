#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct giocatore
{
    char nickname[50];
} Giocatore;

int main()
{
    int scelta;
    Giocatore giocatore1;
    do{
    printf("\ninserisci il tuo nickname: ");
    scanf("%s", giocatore1.nickname);
    printf("\nil tuo nickname è: %s", giocatore1.nickname);
    printf("\nconfermare? (1 si, 2 no): ");
    scanf("%d", &scelta);
    }while(scelta != 1);

    printf("\n\n\t\tBENVENUTO %s IN BATTAGLIA NAVALE \n\n", giocatore1.nickname);

    
     srand(time(NULL));

       int dimensione;
    printf("Quanto vuoi sia grande la tabella? ");
    scanf("%d", &dimensione);
    int tabella[dimensione][dimensione];

    // Inizializzazione della tabella
    for (int i = 0; i < dimensione; i++) {
        for (int j = 0; j < dimensione; j++) {
            tabella[i][j] = 0;  // Tutti i punti inizialmente sono vuoti
        }
    }

    printf("\nLa tabella iniziale:\n");
    for (int i = 0; i < dimensione; i++) {
        for (int j = 0; j < dimensione; j++) {
            printf("%2d ", tabella[i][j]);  // Stampa la tabella
        }
        printf("\n");
    }

       int min, max;
    do
    {
        printf("\nInserisci la dimensione minima per le navi: ");
        scanf("%d", &min);
        if (min <= 0 || min > dimensione) {
            printf("La dimensione minima deve essere maggiore di zero e minore di %d.\n", dimensione);
        }
    } while (min <= 0 || min > dimensione);
    
    do
    {
        printf("\nInserisci la dimensione massima per le navi: ");
        scanf("%d", &max);
        if (max < min || max >= (dimensione / 2) ) {
            printf("La dimensione massima deve essere maggiore di %d e massimo la metà di %d.\n", min, dimensione);
        }
    } while (max < min || max > (dimensione / 2));

    printf("\nDimensioni delle navi inserite correttamente: Min = %d, Max = %d\n", min, max);

    //inserisco le navi casualmente nella tabella
        int c = 4; //contatore navi

       for(int i = 0;i < dimensione; i++)
        {
            for(int j = 0; j < dimensione; j++)
            {
                if(tabella[i][j] == 0)
                {
                    tabella[i][j] = (rand() % 100 < 20) ? 1 : 0; // 20% per 1, 80% per 0
                    if(tabella[i][j] == 1)
                    {
                        double random = (double)rand() / RAND_MAX;  // Genera un numero casuale tra 0 e 1

                         int n;

                        if (random < 0.50) {
                             n = min;  // 50% di possibilità
                             c++;
                             double random = (double)rand() / RAND_MAX;  // Genera un numero casuale tra 0 e 1
                             if (random < 0.50) {
                                    //nave messa in altezza
                                    int z = i;
                                    int f = z - 1;
                                    for(int k = 0;k <= min; k++)
                                    {   
                                        if(tabella[z][j] == 0 || tabella[z][j] == '0')
                                        {
                                            tabella[z][j] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[f][j] == 1;
                                            f--;

                                        }
                                    }


                             }
                             else{
                                //nave messa in larghezza
                                    int z = j;
                                    int f = z - 1;
                                    for(int k = 0;k <= min; k++)
                                    {   
                                        if(tabella[i][z] == 0 || tabella[i][z] == '0')
                                        {
                                            tabella[i][z] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[i][f] == 1;
                                            f--;

                                        }
                                    }
                             }

                        } else if (random < 0.75) {
                            n = min + rand() % (max - min + 1);  // 25% di possibilità di valore nell'intervallo [min, max]
                            c++;
                             double random = (double)rand() / RAND_MAX;  // Genera un numero casuale tra 0 e 1
                             if (random < 0.50) 
                             {
                                     //nave messa in altezza
                                    int z = i;
                                    int f = z - 1;
                                    for(int k = 0;k <= max; k++)
                                    {   
                                        if(tabella[z][j] == 0 || tabella[z][j] == '0')
                                        {
                                            tabella[z][j] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[f][j] == 1;
                                            f--;

                                        }
                                    }

                             }
                             else
                             {
                                    // nave messa in larghezza
                                int z = j;
                                    int f = z - 1;
                                    for(int k = 0;k <= min; k++)
                                    {   
                                        if(tabella[i][z] == 0 || tabella[i][z] == '0')
                                        {
                                            tabella[i][z] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[i][f] == 1;
                                            f--;

                                        }
                                    }
                             }


                        } else {
                            n = max;  // 25% di possibilità
                            c++;
                            double random = (double)rand() / RAND_MAX;  // Genera un numero casuale tra 0 e 1
                             if (random < 0.50) {
                                    //nave messa in altezza
                                    int z = i;
                                    int f = z - 1;
                                    for(int k = 0;k <= max; k++)
                                    {   
                                        if(tabella[z][j] == 0 || tabella[z][j] == '0')
                                        {
                                            tabella[z][j] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[f][j] == 1;
                                            f--;

                                        }
                                    }

                             }
                             else
                             {
                                // nave messa in larghezza
                                int z = j;
                                    int f = z - 1;
                                    for(int k = 0;k <= min; k++)
                                    {   
                                        if(tabella[i][z] == 0 || tabella[i][z] == '0')
                                        {
                                            tabella[i][z] = 1;
                                            z++;
                                        }
                                        else
                                        {
                                            tabella[i][f] == 1;
                                            f--;

                                        }
                                    }

                             }
                         }
                    }
                }
            }
        }
           printf("\nLa tabella modificata:\n");
                                    for (int i = 0; i < dimensione; i++) {
                                        for (int j = 0; j < dimensione; j++) {
                                            printf("%2d ", tabella[i][j]);  // Stampa la tabella
                                        }
                                        printf("\n");
                                    }
}