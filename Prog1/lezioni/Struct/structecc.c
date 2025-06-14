#include <stdio.h>


        /* ALLOCAZIONE CLASSICA */
struct record {
    char *nome;
    char *cognome;
    float saldo;
    struct record *next; //puntatore alla struttura(record) stessa
} s1 , s2;

        /* ALLOCAZIONE DINAMICA */
struct record1{
    float x;
    float y;
};


int main()
{ 

    /* ALLOCAZIONE CLASSICA */
    
struct record s1 = {};
struct record s2 = {"Mario", "Rossi", 100.0};
struct record s2 = {.cognome = "Rossi" , .nome = "Mario" , .saldo = 100.0};

s1.nome = "Elena";
s1.cognome = "Bianchi";
s1.saldo = 500.0;

   /* ALLOCAZIONE DINAMICA */

    struct record1 *rec = (struct record1 *) malloc(sizeof(struct record1));
    if (rec == NULL) {
        printf("Errore di allocazione della memoria!\n");
        return 1; // Termina il programma in caso di errore
    }

    rec->x = 0.3; // equivalente a (*rec).x
    rec->y = 0.7;


    printf("x = %.2f, y = %.2f\n", rec->x, rec->y);

   
    free(rec);  // Deallocazione della memoria

}



