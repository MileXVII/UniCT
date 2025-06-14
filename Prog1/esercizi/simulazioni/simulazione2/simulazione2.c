#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    double *stack;
    int top;
    int Empty;
} pila;

typedef struct {
    double x;
    double y;
    int n;
} parametri;

int readInput(parametri *ptr);
void genDouble(parametri *ptr, pila *p);
void buildStack(parametri *ptr, pila *p);
void stampaStack(pila *p);
void buildArray(pila *p, double arr[], parametri *ptr);
void elabValues(double arr[], parametri *ptr);
int push(double NuovoElemento, parametri *ptr, pila *p);
double pop(pila *p);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 4) {
        printf("\nErrore: numero di parametri passati al programma non corretto.\n");
        return 1;
    }

    parametri *ptr = malloc(sizeof(parametri));
    pila *p = malloc(sizeof(pila));

    if (!ptr || !p) {
        printf("\nErrore nell'allocazione della memoria.\n");
        return 1;
    }

    ptr->x = atof(argv[1]);
    ptr->y = atof(argv[2]);
    ptr->n = atoi(argv[3]);

    if (readInput(ptr)) {
        free(ptr);
        free(p);
        return 1;
    }

    buildStack(ptr, p);

    double *arr = malloc(ptr->n * sizeof(double));
    if (!arr) {
        printf("\nErrore nell'allocazione dell'array.\n");
        free(ptr);
        free(p->stack);
        free(p);
        return 1;
    }

    buildArray(p, arr, ptr);

    elabValues(arr, ptr);

    free(arr);
    free(p->stack);
    free(p);
    free(ptr);

    return 0;
}

int readInput(parametri *ptr) {
    if (ptr->x >= 1.0 && ptr->x <= 1000.0 && ptr->y >= 1.0 && ptr->y <= 1000.0) {
        if ((ptr->y - ptr->x) > 500.0) {
            if (ptr->n >= 20 && ptr->n <= 30) {
                printf("\nInserimento avvenuto con successo!\n");
                return 0;
            } else {
                printf("\nErrore: 'n' deve essere compreso tra 20 e 30.\n");
                return 1;
            }
        } else {
            printf("\nErrore: 'y - x' deve essere > 500.0.\n");
            return 1;
        }
    } else {
        printf("\nErrore: 'x' e 'y' devono appartenere al range [1.0, 1000.0].\n");
        return 1;
    }
}

void buildStack(parametri *ptr, pila *p) {
    p->Empty = -1;
    p->top = p->Empty;
    p->stack = malloc(ptr->n * sizeof(double));
    if (!p->stack) {
        printf("\nErrore nell'allocazione della memoria per lo stack.\n");
        exit(1);
    }

    genDouble(ptr, p);
    stampaStack(p);
}

int push(double NuovoElemento, parametri *ptr, pila *p) {
    if (p->top == ptr->n - 1) {
        printf("\nErrore: la pila è piena!\n");
        return 0;
    }
    p->stack[++p->top] = NuovoElemento;
    return 1;
}

double pop(pila *p) {
    if (p->top == p->Empty) {
        printf("\nErrore: la pila è vuota!\n");
        return -1; // Valore di errore
    }
    return p->stack[p->top--];
}

void genDouble(parametri *ptr, pila *p) {
    for (int i = 0; i < ptr->n; i++) {
        double randomValue = ((double)rand() / RAND_MAX) * (ptr->y - ptr->x) + ptr->x;
        push(randomValue, ptr, p);
    }
}

void stampaStack(pila *p) {
    if (p->top == p->Empty) {
        printf("\nLo stack è vuoto.\n");
    } else {
        printf("\nContenuto dello stack:\n");
        for (int i = p->top; i >= 0; i--) {
            printf("| %0.2f |\n", p->stack[i]);
        }
    }
}

void buildArray(pila *p, double arr[], parametri *ptr) {
    printf("\nSvuotamento dello stack e creazione dell'array:\n");
    for (int i = ptr->n - 1; i >= 0; i--) {
        arr[i] = pop(p);
        printf("| %0.2f |\n", arr[i]);
    }
    printf("\n");
}

void elabValues(double arr[], parametri *ptr) {
    double sum = 0.0;
    for (int i = 0; i < ptr->n; i++) {
        sum += arr[i];
    }
    double media = sum / ptr->n;

    printf("\nMedia aritmetica: %0.2f\n", media);
    printf("Valori maggiori della media:\n");
    for (int i = 0; i < ptr->n; i++) {
        if (arr[i] > media) {
            printf("| %0.2f |\n", arr[i]);
        }
    }
    printf("\n");
}
