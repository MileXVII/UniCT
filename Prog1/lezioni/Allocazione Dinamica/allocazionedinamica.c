#include <stdio.h>
#include <stdlib.h>

void printArray(int a[] , int dim)
{
    printf("\n");
    for(int i = 0;i < dim;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    /* Dimensione FISSA */
    int a[] = {1 , 2 , 3 , 4 , 5};
    int dimA = 5;

    printf("\nArray statico di %d elementi:", dimA);
    printArray(a , dimA);

    /* Array DINAMICI */

    int numElementi = 10;
    int *p;

    /* MALLOC - malloc(numElementi * numbyte); */
    
    p = malloc(numElementi * sizeof(int*));        //riserva un det. num. di celle all'interno della memoria dinamica
                                                  //se ne frega del contenuto
     for(int i = 0;i < numElementi; i++)
      {
        p[i] = i;
      }

      printf("\nArray dinamico con malloc: ");
      printArray(p , numElementi); 

      /* CALLOC - calloc(nulElementi , dimensione di uno degli elementi); */

      p = (int*) calloc(numElementi , sizeof(int)); //azzera tutte le celle della memoria dinamica che va a prendere
                                                    //prima di restituire l'array ne azzera il contenuto

    for(int i = 0;i < numElementi; i++)
      {
        p[i] = i;
      }

      printf("\nArray dinamico con calloc: ");
      printArray(p , numElementi); 

      /* REALLOC - recalloc(ArrayDinamico , NewNumByte); */

      numElementi = 15;
      p = (int*) realloc(p , numElementi * sizeof(int)); //utilizzabile anche per accorciare
                                                         //p = (int*) realloc(p , 7 * sizeof(int));
      for(int i = 0;i < numElementi; i++)
      {
        p[i] = i;
      }  
      printArray(p , numElementi); 

      /* FREE - free(ArrayDinamico); */
      free(p); //questo array non mi serve più, non le cancella ma sono
}