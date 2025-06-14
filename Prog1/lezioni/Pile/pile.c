#include <stdio.h>
#include <stdbool.h>

#define LIMITE 5 
#define EMPTY (-1)

int stack[LIMITE];
int top = EMPTY;

bool push(int);
int pop();
void stampaStack();   
void eliminaStack(); 

int main()
{
    int elemento;
    int scelta;  
    while (true)
    {
        printf("\nMenu:\n");
        printf("1. Inserisci un elemento nello stack\n");
        printf("2. Estrai un elemento dallo stack\n");
        printf("3. Visualizza lo stack\n");
        printf("4. Elimina la pila\n");
        printf("5. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            printf("Inserisci un elemento da inserire nello stack: ");
            scanf("%d", &elemento);
            if (push(elemento))
                printf("Elemento %d inserito correttamente.\n", elemento);
            else
                printf("Errore: lo stack è pieno!\n");
            break;

        case 2:
            elemento = pop();
            if (elemento != EMPTY)
                printf("Elemento estratto: %d\n", elemento);
            else
                printf("Errore: lo stack è vuoto!\n");
            break;

        case 3:
            stampaStack();
            break;

        case 4:
            eliminaStack();
            printf("La pila è stata eliminata.\n");
            break;

        case 5:
            printf("Uscita dal programma.\n");
            return 0;

        default:
            printf("Opzione non valida. Riprova.\n");
        }
    }
}

bool push(int nuovoElemento) 
{
    if (top == LIMITE - 1)
        return false;

    top++;
    stack[top] = nuovoElemento;
    return true;
}

int pop()
{
    if (top == EMPTY)
        return EMPTY;

    int elementoEstratto = stack[top]; 
    top--;
    return elementoEstratto;
}

void stampaStack()
{
    if (top == EMPTY)
    {
        printf("Lo stack è vuoto.\n");
    }
    else
    {
        printf("Contenuto dello stack:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%02d\n", stack[i]);
        }
    }
}

void eliminaStack()
{
    top = EMPTY; 
}
