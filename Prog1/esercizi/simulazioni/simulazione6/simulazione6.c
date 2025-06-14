#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* input_filename;
    char* output_filename;
} parametri;

typedef struct {
    char nome[50];
    char cognome[50];
    int età;
    float altezza;
} dati;

void error(char* err) {
    fprintf(stderr, "\nERRORE: %s", err);
    exit(1);
}

parametri decodeParameter(int argc, char* argv[]);
int readHeader(FILE* file); 
void readFile(FILE* file, dati* Persona, int n); 
int* extractAges(FILE* file, dati* Persona, int n);
float sortArray(int n, int z[n]);
void printArray(int n , int *z);
float calculateAvarageHeight(int n, float mediana, dati* Persona);
void writeOutput(dati* Persona, parametri ptr,int n, float mediah);

int main(int argc, char* argv[]) {
    printf("\n=======Punto A decodeParameter=======\n");
    parametri ptr = decodeParameter(argc, argv);

    printf("\n=======Punto B readHeader & readFile=======\n");
    FILE* file = fopen(ptr.input_filename, "r");
    if (file == NULL) {
        error("Impossibile aprire il file input");
    }

    int n = readHeader(file);
    printf("Numero di righe: %d\n", n);

    dati* Persona = malloc(n * sizeof(dati));
    if (Persona == NULL) {
        error("Errore di allocazione della memoria");
    }

    readFile(file, Persona, n);

    printf("\n=======Punto C extractAges & sortArray=======\n");
    int *z = extractAges(file, Persona, n);
    printf("\narray delle età:");
    printArray(n , z);
    printf("\narray delle età ordinato:");
    float mediana = sortArray(n , z);
    printArray(n , z);
    printf("\n=======Punto D CalculateAvarageHeight=======\n");
    float mediah = calculateAvarageHeight(n, mediana , Persona);
    printf("\n=======Punto E WriteOutput=======\n");
    writeOutput(Persona, ptr, n, mediah);

    free(Persona);
    free(z);
    fclose(file);

    return 0;
}

parametri decodeParameter(int argc, char* argv[]) {
    parametri ptr;
    if (argc != 3) {
        error("Numero di parametri non valido");
    }
    ptr.input_filename = argv[1];
    ptr.output_filename = argv[2];
    if (strcmp(ptr.input_filename + strlen(ptr.input_filename) - 4, ".txt") != 0 && strcmp(ptr.output_filename + strlen(ptr.output_filename) - 4, ".txt") != 0) {
        printf("\nParametri passati: %s %s", ptr.input_filename, ptr.output_filename);
        error("I file passati devono essere di tipo .txt");
    }

    printf("\nParametri passati: %s %s", ptr.input_filename, ptr.output_filename);
    return ptr;
}

int readHeader(FILE* file) {
    int n = 0;
    if (fscanf(file, "%d", &n) != 1) {
        error("Errore nella lettura dell'header");
    }
    return n;
}

void readFile(FILE* file, dati* Persona, int n) {
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d %f", Persona[i].nome, Persona[i].cognome, &Persona[i].età, &Persona[i].altezza);
    }
}

int* extractAges(FILE* file, dati* Persona, int n){
    int* z = malloc(n * sizeof(int));
    if (z == NULL) {
        error("Allocazione di memoria per l'array z non riuscita");
    }

    for (int i = 0; i < n; i++) {
        z[i] = Persona[i].età; 
    }
    return z;
}

float sortArray(int n, int z[n]) {
    int temp;
    float mediana;
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  // n - i - 1 vuol dire che ignora gli elemeneti gia ordinati
            if (z[j] > z[j + 1]) {  
                temp = z[j];
                z[j] = z[j + 1];
                z[j + 1] = temp;
            }
        }
    }
    if (n % 2 == 1) {  
        mediana = z[n / 2];
    } else {  
        mediana = (z[n / 2 - 1] + z[n / 2]) / 2;
    }

    return mediana;
}

float calculateAvarageHeight(int n, float mediana, dati* Persona){
    float mediah = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(Persona[i].età > mediana){
            mediah += Persona[i].altezza;
            count++;
        }
    }
    mediah = mediah / count;

    printf("\nmedia dell'altezza delle persone con età superiore alla mediana: %.2f", mediah);
    return mediah;
}

void writeOutput(dati* Persona, parametri ptr,int n, float mediah){
    FILE *file = fopen(ptr.output_filename, "w");
    if(file == NULL){
        error("Errore nell'apertura del file output");
    }
    for(int i = 0; i < n; i++){
        if(Persona[i].altezza > mediah){
            fprintf(file, "[%d] %s %s, Età: %d, Altezza: %.2f\n", i, Persona[i].nome , Persona[i].cognome ,Persona[i].età, Persona[i].altezza);
        }
    }
    fclose(file);

}

void printArray(int n , int *z){
    printf("\n ");
    for(int i = 0; i < n; i++){
        printf("%d ", z[i]);
    }

}

