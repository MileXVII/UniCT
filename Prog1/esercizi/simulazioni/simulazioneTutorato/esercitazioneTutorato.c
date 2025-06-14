#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void error(char* err){

    fprintf(stderr, "\n[ERRORE]: %s",err );
    exit(1);
}
typedef struct{
    char* filename;
}parametri;

typedef struct Node{
    int val;
    struct Node *next;
}node;

parametri decodeParameters(int argc , char* argv[]);
void push(int val, node** p);
int pop(node** p);
node* readFile(FILE *file);
void printstack(node* p);
float getMean(node** p);
int stakSize(node **p);
node* fillP(FILE *file , float media , int SIZE);
int* transferP(node** p, int SIZE);
void sort(int SIZE, int A[SIZE]);


int main(int argc , char* argv[]){

    puts("Michael Raneri , N° di matricola: 1000072190");
    printf("\n======Punto A======");
    parametri prt = decodeParameters(argc , argv);
    printf("\n======Punto B======");
    FILE *file = fopen(prt.filename, "r");
    if(file == NULL){
        error("Impossibile aprire il file");
    }
    node* p = readFile(file); 
    printstack(p);
    printf("\n======Punto C======");
    int SIZE = stakSize(&p);
    float media = getMean(&p);
    printf("\n======Punto D======");
    fillP(file , media , SIZE);
    printstack(p);
    printf("\n======Punto E======\n");
    int *A = transferP(&p , SIZE);

    sort(SIZE, A);

    for(int i = 0; i< SIZE; i++){
        printf("\n%d", A[i]);
    }

    fclose(file);
    while (p != NULL) {
        node* temp = p;
        p = p->next;
        free(temp);
    }
    free(A);
    return 0;
}

parametri decodeParameters(int argc , char* argv[]){

    if(argc != 2){
        error("Numero di parametri passati non corretto");
    }

    parametri prt;
    prt.filename = argv[1];

    if(strlen(prt.filename) > 100)
    {
        error("Nome del file troppo lungo");
    }

    if(strcmp(prt.filename + strlen(prt.filename) - 4, ".txt") != 0){
        error("Il file passato come parametro deve avere estensione .txt");
    }

    printf("\nParametri passati: %s", prt.filename);
    return prt;

}

void push(int val, node** p){
    node* new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = *p;
    *p = new;
}

int pop(node** p){

    if(*p == NULL){
        return -1;
    }

    node* del = *p;
    *p = del->next;
    int n = del->val;
    free(del);
    return n;
}

node* readFile(FILE *file){
    node *p = NULL;
    int n;
    char line[13]; 
    while(fgets(line, 13 , file)){
        n = atoi(line);
        push(n , &p);
    }
    return p;
}

void printstack(node* p){
    node* current = p;
    while(current != NULL){
        printf("\n%d -->", current->val);
        current = current->next;
    }
    printf(" NULL\n");
}

float getMean(node** p) {

    float media = 0.0;
    int count = 0;
    int sum = 0;
    while (*p != NULL) {
        int val = pop(p);  
        sum += val;
        count++;
    }

    if (count > 0) {
        media = (float)sum / count;
    }

    printf("La media dei valori contenuti nella pila e\': %f\n", media);
    return media;
}

int stakSize(node **p){
    node* current = *p;
    int count = 0;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}

node* fillP(FILE *file , float media , int SIZE){
    node *p = NULL;
    int x;
    int y;
    char line[13];

    for(int i = 0; i < SIZE; i++){
        
        if(i < 1){
            fgets(line, 13, file);
            x = atoi(line);
            push(x , &p);
        }

        fgets(line, 13, file);
        x = atoi(line);
        if(x > media)
        {
            push(x , &p);
        }
        else
        {
            int y = pop(&p);
            float val = (x + y)/2;
            
            push(val , &p); //val verrà troncato in intero
        }
    }

    return p;
}

int* transferP(node** p, int SIZE){
    int* A = (int*)malloc(SIZE * sizeof(int));
    node* current = *p;
    int i = 0;
    while(current != NULL){
        A[i] = current->val;
        current = current->next;
        i++;
    }

    return A;
}

void sort(int SIZE, int A[SIZE]){

    int tmp;
    int i = 0;
    for(i = 0; i < SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(A[j] > A[j + 1]){
                tmp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = tmp;
            }
        }
    }

}