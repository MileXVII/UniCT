#include <stdio.h>
#include <math.h>

int main()
{
    int A = 0,B = 0,C = 0;
    int tubi[5];
    int c = 0;
    int dispariA = 0, dispariB = 0, dispariC = 0;
    
        printf("\nDammi 5 numeri distinti da 1 a 15\n");

        while(c<5)
        {
                int n;

                printf("\ndammi un numero da 1 a 15: ");
                scanf("%d", &n);

            if (n < 1 || n > 15) 
            {
                printf("\nil numero deve essere compreso tra 1 e 15 ");
                continue; //skippa
            }

    int j;

            for(j = 0; j < c; j++)
            {
                if (tubi[j] == n)
                {
                        printf("\nnumero già inserito, riprova.\n");
                        break; //esce dal for
                }
            }
        
            if(j == c)
            {
                tubi[c] = n;
                c++;
            }

            switch(n)
            {
            case 1: case 5: case 6: case 10:
            
                A++;
                if(n % 2 != 0)
                {
                    dispariA++;
                }
                break;

            case 2: case 3: case 4: case 7: case 8: case 9:

                B++;
                if(n % 2 != 0)
                {
                    dispariB++;
                }
                break;

            case 11: case 12: case 13: case 14: case 15: 

                C++;
                if(n % 2 != 0)
                {
                    dispariC++;
                }
            }
        }
    int M;
    do
    {
      printf("\ninserisci un totale di minuti nella quale i tubi specificati porteranno acqua alla propria vasca: ");
    scanf("%d", &M);
            
    } while(M<=0);

    printf("\n ----- RIEPILOGO -----\n");
    printf("Tubi nella vasca A: %d.\nTubi nella vesca B: %d.\nTubi nella vasca C: %d.", A , B , C);
    printf("\nMinuti inseriti: %d", M);
    
    int pariA = A - dispariA;  
    int pariB = B - dispariB;  
    int pariC = C - dispariC;  

    int vascaA = (dispariA * 60 + pariA * 120) * M;
    int vascaB = (dispariB * 60 + pariB * 120) * M;
    int vascaC = (dispariC * 60 + pariC * 120) * M;

    printf("\nQuantità d'acqua raccolta:\n");
    printf("Vasca A: %d litri;\n", vascaA);
    printf("Vasca B: %d litri;\n", vascaB);
    printf("Vasca C: %d litri.\n", vascaC);
}