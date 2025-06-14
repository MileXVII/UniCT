#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len_str 20


typedef struct 
{
    char* file_input;
    char* file_output;
}parametri;

typedef struct 
{
    char *key[200];
    int lenght[200];
}strctr;

parametri readInput(int argc , char* argv[]);
strctr buildArray(parametri ptr);
strctr filter(strctr str);
strctr createSet(strctr str);
void printArray(strctr str);
void save(parametri ptr , strctr str);
void read(parametri ptr);

int main(int argc , char* argv[])
{
    printf("\n===========Punto A===========\n");
    parametri ptr = readInput(argc , argv);
    printf("Punto A completato.\n");

    printf("\n1st file name: %s; 2nd file name: %s " , ptr.file_input , ptr.file_output);

    printf("\n===========Punto B===========\n");
    strctr str = buildArray(ptr);
    printf("Punto B completato.\n");

    printf("\n===========Punto C===========\n");
    str = filter(str);
    printf("Punto C completato.\n");

    printf("\n===========Punto D===========\n");
    str = createSet(str);
    printf("Punto D completato.\n");

    printf("\n===========Punto E===========\n");
    printArray(str);
    printf("Punto E completato.\n");

    printf("\n===========Punto F===========\n");
    save(ptr , str);
    printf("Punto F completato.\n");

    printf("\n===========Punto G===========\n");
    read(ptr);
    printf("Punto G completato.\n");

     for (int i = 0; i < 200; i++) {
        if (str.key[i] != NULL) {
            free(str.key[i]);  
        }
    }
    
    return 0;
}

void error(char* err){
fprintf(stderr, "\n[ERROR]: %s", err);
exit(1);
}

parametri readInput(int argc , char* argv[]){

    if(argc != 3){
        error("Numero di parametri passati non valido!");
    }

    if(strlen(argv[1]) > 100 && strlen(argv[2]) > 100){
        error("Nome di un file troppo grande!");
    }

    parametri ptr;
    ptr.file_input = argv[1];
    ptr.file_output = argv[2];

    if(strcmp(ptr.file_input + strlen(ptr.file_input) - 4 , ".txt") != 0){
        error("Il primo file passato deve essere un file.txt");
    }else {
        if(strcmp(ptr.file_output + strlen(ptr.file_output) - 4 , ".bin") != 0){
            error("Il secondo file deve essere un file.bin");
        }
    }

    return ptr;

}

strctr buildArray(parametri ptr){
    strctr str;
    FILE *file = fopen(ptr.file_input, "r");
    char parola[len_str];  

    for (int i = 0; i < 199; i++) {
    str.key[i] = NULL;  
    }

    for (int i = 0; i < 199; i++) {
        fscanf(file, "%s", parola);  
        str.key[i] = malloc(strlen(parola) + 1);  
        strcpy(str.key[i], parola);  
        str.lenght[i] = strlen(parola);  
    }

    fclose(file);  
     
    return str;  
}


strctr filter(strctr str){
    for(int i = 0; i < 200; i++){

        int k = 0;

        for(int j = 0; j < str.lenght[i]; j++){
            if(!strchr(",;:." , str.key[i][j]))
            {
                str.key[i][k++] = str.key[i][j];
            }
        }           
        str.key[i][k] = '\0';  
        str.lenght[i] = k;                                
    }

    return str;
}

strctr createSet(strctr str){
    for(int i = 0; i < 199; i++){
        if(strcmp(str.key[i] , str.key[i+1]) == 0){
            str.lenght[i] = -1;
        }
    }
    return str;
}

void printArray(strctr str) {
    for (int i = 0; i < 200; i++) {
            printf("\nargv[%d]: %s | lunghezza: %d\n", i + 1, str.key[i], str.lenght[i]);
    }
}

void save(parametri ptr , strctr str){
    FILE *file = fopen(ptr.file_output, "w");
    if(file == NULL){
        error("impossibile aprire file output in scrittura");
    }

    for(int i = 0; i < 200; i++){
        size_t written = fwrite(str.key[i], sizeof(char) , strlen(str.key[i]), file);
        if(written != strlen(str.key[i])){
            error("impossibile scrivere parola");
        }
    }

    fclose(file);
}

void read(parametri ptr){
    FILE* file = fopen(ptr.file_input, "r");
    if(file == NULL){
        error("impossibile aprire file output in lettura");
    }
    
    char Str[21];

     while (fgets(Str, sizeof(Str), file)) {
            printf("%s", Str);
    } 

    fclose(file);

}

