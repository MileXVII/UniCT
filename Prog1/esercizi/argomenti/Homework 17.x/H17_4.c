#include <stdio.h>
#include <string.h>

#define STR 5
#define LunghezzaSTR 10

int main() {
    char M[STR][LunghezzaSTR]; //array di stringhe [numero di stringhe][lunghezza di ogni stringa]

    printf("\nScrivi alcuni verbi all'infinito:\n");

    for (int i = 0; i < STR; i++) {
        do {
            printf("Inserisci il verbo %d: ", i + 1);
            scanf("%9s", M[i]); // Limita la lunghezza a LunghezzaSTR - 1
        } while (strlen(M[i]) < 3);
    }

    printf("\nVerifica dei suffissi:\n");
    for (int i = 0; i < STR; i++) {
        char *verbo = M[i];
        char *p = strtok(verbo, "");  // Dividerà la stringa nei separatori di spazio vuoto //Es. "gioco a calcio" diventa: "gioco" "a" "calcio"

        while (p != NULL) {
            if (strlen(p) >= 3) {
                if (strcmp(&p[strlen(p) - 3], "are") == 0) {
                    printf("Il verbo '%s' termina con 'are'.\n", p);
                } else if (strcmp(&p[strlen(p) - 3], "ere") == 0) {
                    printf("Il verbo '%s' termina con 'ere'.\n", p);
                } else if (strcmp(&p[strlen(p) - 3], "ire") == 0) {
                    printf("Il verbo '%s' termina con 'ire'.\n", p);
                } else {
                    printf("Il verbo '%s' non termina con 'are', 'ere' o 'ire'.\n", p);
                }
            }
            p = strtok(NULL, "");  // Prossima parola
        }
    }

    return 0;
}
