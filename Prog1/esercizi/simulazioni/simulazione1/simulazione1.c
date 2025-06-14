#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int tail;
    char **queue;
} coda;

typedef struct {
    int x;
    int y;
    char a;
    char b;
    int n;
} parametri;

static int readInput(parametri *ptr);
void genString(char **string, parametri *ptr);
void Buildqueue(coda *p, parametri *ptr, char **string);
bool enqueue(char *NuovoElemento, coda *p);
char* dequeue(coda *p);
void stampa(coda *p);
void elabString(char *str);
void printstring(coda *p);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc != 6) {
        printf("Errore: numero di argomenti errato. Uso: <a> <b> <x> <y> <n>\n");
        return 1;
    }

    parametri *ptr = malloc(sizeof(parametri));
    if (!ptr) {
        printf("Errore nell'allocazione della memoria per parametri.\n");
        return 1;
    }
    ptr->x = atoi(argv[3]);
    ptr->y = atoi(argv[4]);
    ptr->a = argv[1][0];
    ptr->b = argv[2][0];
    ptr->n = atoi(argv[5]);

    if (readInput(ptr)) {
        free(ptr);
        return 1;
    }

    coda *p = malloc(sizeof(coda));
    if (!p) {
        printf("Errore nell'allocazione della memoria per la coda.\n");
        free(ptr);
        return 1;
    }
    p->tail = 0;

    char **string = malloc(ptr->n * sizeof(char *));
    if (!string) {
        printf("Errore nell'allocazione della memoria per le stringhe.\n");
        free(p);
        free(ptr);
        return 1;
    }

    Buildqueue(p, ptr, string);
    printstring(p);

    for (int i = 0; i < ptr->n; i++) {
        free(string[i]);
    }

    free(string);
    free(p->queue);
    free(p);
    free(ptr);

    return 0;
}

static int readInput(parametri *ptr) {
    printf("\npunto A: readInput() \n");
    if (ptr->a >= 'a' && ptr->a <= 'z') {
        if (ptr->b < 'a' || ptr->b > 'z' || ptr->a >= ptr->b) {
            printf("Errore: 'b' deve essere maggiore di 'a' e entrambi devono essere minuscoli.\n");
            return 1;
        }
    } else if (ptr->a >= 'A' && ptr->a <= 'Z') {
        if (ptr->b < 'A' || ptr->b > 'Z' || ptr->a >= ptr->b) {
            printf("Errore: 'b' deve essere maggiore di 'a' e entrambi devono essere maiuscoli.\n");
            return 1;
        }
    } else {
        printf("Errore: 'a' e 'b' devono essere entrambi lettere.\n");
        return 1;
    }

    if (ptr->x < 5 || ptr->x > 30 || ptr->y < 5 || ptr->y > 30 || (ptr->y - ptr->x) <= 5) {
        printf("Errore: 'x' e 'y' devono essere tra 5 e 30, con 'y - x > 5'.\n");
        return 1;
    }

    if (ptr->n < 15 || ptr->n > 25) {
        printf("Errore: 'n' deve essere tra 15 e 25.\n");
        return 1;
    }

    return 0;
}

void genString(char **string, parametri *ptr) {
    printf("\npunto B: genString() \n");
    for (int i = 0; i < ptr->n; i++) {
        int L = rand() % (ptr->y - ptr->x + 1) + ptr->x;
        string[i] = malloc((L + 1) * sizeof(char));
        if (!string[i]) {
            printf("Errore nell'allocazione della memoria per una stringa.\n");
            exit(1);
        }
        for (int j = 0; j < L; j++) {
            string[i][j] = ptr->a + rand() % (ptr->b - ptr->a + 1);
        }
        string[i][L] = '\0';
    }
}

bool enqueue(char *NuovoElemento, coda *p) {
    printf("\nenqueue() \n");
    p->queue[p->tail++] = NuovoElemento;
    return true;
}

char* dequeue(coda *p) {
    printf("\ndequeue() \n");
    if (p->tail == 0) {
        printf("Coda vuota!\n");
        return NULL;
    }

    char *deleted = p->queue[0];
    for (int i = 1; i < p->tail; i++) {
        p->queue[i - 1] = p->queue[i];
    }

    p->tail--;
    return deleted;
}

void Buildqueue(coda *p, parametri *ptr, char **string) {
    printf("\npunto C: Buildqueue() \n");
    p->queue = malloc(ptr->n * sizeof(char *));
    if (!p->queue) {
        printf("Errore nell'allocazione della memoria per la coda.\n");
        exit(1);
    }

    genString(string, ptr);
    for (int i = 0; i < ptr->n; i++) {
        enqueue(string[i], p);
    }

    stampa(p);
}

void stampa(coda *p) {
    printf("\nstampa() \n");
    printf("\nContenuto della coda:\n");
    for (int i = 0; i < p->tail; i++) {
        printf("%s\n", p->queue[i]);
    }
}

void elabString(char *str) {
    printf("\npunto E: elabString() \n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", str[i])) {
            str[i] = 'X';
        }
    }
}

void printstring(coda *p) {
    printf("\nPunto D: printstring() \n");
    while (p->tail > 0) {
        char *str = dequeue(p);
        elabString(str);
        printf("%s\n", str);
        free(str);
    }
}
