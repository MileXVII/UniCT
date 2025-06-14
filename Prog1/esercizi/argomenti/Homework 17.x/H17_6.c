#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define stringhe 5
#define lunghezza 50  // Aumentato per evitare troncamento

int main() {
    char M[stringhe][lunghezza];
    int a, b, c;

    printf("\nInserisci %d parole o frasi:\n", stringhe);

    // Lettura delle stringhe
    for (int i = 0; i < stringhe; i++) {
        printf("\nInserisci una parola o frase: ");
        fgets(M[i], lunghezza, stdin); // Utilizzo fgets per leggere una riga di testo fino alla new line \n
        
        M[i][strcspn(M[i], "\n")] = '\0'; // Rimuove il carattere di newline (\n) aggiunto da fgets
    }

    // Analisi delle stringhe
    for (int i = 0; i < stringhe; i++) {
        a = 0; // Contatore per lettere minuscole
        b = 0; // Contatore per numeri
        c = 0; // Contatore per spazi

        printf("\nParola/Frase %d: %s", i + 1, M[i]);

        for (int j = 0; j < strlen(M[i]); j++) {
            if (islower(M[i][j])) {
                a++;
            }
            if (isdigit(M[i][j])) {
                b++;
            }
            if (isspace(M[i][j])) {
                c++;
            }
        }

        printf("\nHa %d lettere minuscole", a);
        printf("\nHa %d numeri nella parola o frase", b);
        printf("\nHa %d spazi nella parola o frase\n", c);
    }

    return 0;
}
