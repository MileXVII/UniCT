#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5

int queue[LIMIT]; 
int tail = 0;

// Funzione per inserire un elemento nella coda
bool enqueue(int nuovoElemento) {
    if (tail == LIMIT) {
        printf("Coda piena. Impossibile inserire l'elemento.\n");
        return false;
    }

    queue[tail] = nuovoElemento;
    tail++;
    return true;
}

// Funzione per rimuovere un elemento dalla coda
int dequeue() {
    if (tail == 0) {
        printf("Coda vuota. Impossibile rimuovere un elemento.\n");
        return -1;
    }

    int deleted = queue[0];

    // Sposta tutti gli elementi indietro di una posizione
    for (int i = 0; i < tail - 1; i++) {
        queue[i] = queue[i + 1];
    }

    tail--;
    return deleted;
}

// Funzione per stampare il contenuto della coda
void stampa() {
    if (tail == 0) {
        printf("Coda vuota.\n");
        return;
    }

    printf("Contenuto della coda: ");
    for (int i = 0; i < tail; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Esempio di utilizzo delle funzioni enqueue, dequeue e stampa
    while (true) {
        printf("\nScegli un'opzione:\n");
        printf("1. Inserisci un elemento nella coda\n");
        printf("2. Rimuovi un elemento dalla coda\n");
        printf("3. Mostra il contenuto della coda\n");
        printf("4. Esci\n");
        printf("Scelta: ");

        int scelta;
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Inserisci un numero da aggiungere: ");
                scanf("%d", &n);
                if (enqueue(n)) {
                    printf("Elemento aggiunto con successo.\n");
                }
                break;
            case 2:
                n = dequeue();
                if (n != -1) {
                    printf("Elemento rimosso: %d\n", n);
                }
                break;
            case 3:
                stampa();
                break;
            case 4:
                printf("Uscita...\n");
                return 0;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }

    return 0;
}