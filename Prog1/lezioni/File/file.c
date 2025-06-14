#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int codice;

    printf("Inserisci il codice: ");
    if (scanf("%d", &codice) != 1) {
        printf("Errore: input non valido per il codice.\n");
        return 1;
    }

    // Apri il file in modalità scrittura per sovrascrivere i dati
    FILE *file_handle = fopen("file.txt", "w");
    if (file_handle == NULL) {
        printf("\nErrore nell'apertura del file");
        return 1;
    }

    fprintf(file_handle, "Codice: %d\n", codice);
    printf("\nCodice %d scritto in 'file.txt'.", codice);

    fclose(file_handle);
    printf("\nFile chiuso dopo scrittura iniziale.");

    // Leggi il codice dal file per verifica
    FILE *file_read = fopen("file.txt", "r");
    if (file_read == NULL) {
        printf("\nErrore nell'apertura del file");
        return 1;
    }

    int codice_letto;
    if (fscanf(file_read, "Codice: %d", &codice_letto) == 1) {
        printf("\nCodice trovato nel file: %d", codice_letto);
    } else {
        printf("\nErrore nella lettura del codice dal file.");
    }

    fclose(file_read);
    printf("\nFile chiuso dopo lettura.");

    // Apri il file in modalità append per aggiungere dati
    FILE *file_append = fopen("file.txt", "a");
    if (file_append == NULL) {
        printf("\nErrore nell'apertura del file");
        return 1;
    }

    printf("\n\nInserisci i dati delle mascherine:");

    while (1) {
        char name[30];
        int mask_count;

        printf("\nNome (digita 'fine' per uscire): ");
        scanf("%s", name);

        // Termina se l'utente scrive "fine"
        if (strcmp(name, "fine") == 0) {
            break;
        }

        printf("Numero di mascherine: ");
        if (scanf("%d", &mask_count) != 1 || mask_count <= 0) {
            printf("Numero di mascherine non valido. Interruzione.");
            break;
        }

        fprintf(file_append, "Nome: %s, Numero di mascherine: %d\n", name, mask_count);
        printf("%s ha preso %d mascherine.", name, mask_count);
    }

    fclose(file_append);
    printf("\nFile chiuso dopo append.");

    return 0;
}
