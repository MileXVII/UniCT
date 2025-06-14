#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 16

typedef struct {
    char* filename;
}parametri;

typedef struct nodo{
    int data;
    struct nodo* next;
}Nodo;

void error(char* err);
parametri decoceParameter(int argc , char* argv[]);
Nodo* readFile(FILE* f);
float getMean(Nodo**);
void fillP(FILE* f,Nodo** ptr , float m);
int* transferO(Nodo** ptr);
void bubbleSort(int* A , int n);
void push(int val, Nodo** ptr);
int pop(Nodo **ptr);
void printStack(Nodo* ptr);

int main(int argc , char *argv[])
{
    printf("\n\r\rPUNTO A\r\r");
    parametri ptr = decoceParameter(argc , argv);

    printf("\nFile name: %s\n",ptr.filename);

    printf("\n\r\rPUNTO B\r\r");

    FILE* f = fopen(ptr.filename,"r");
    Nodo* ptr = readFile(f);
    printstack(ptr);

    printf("\n\r\rPUNTO C\r\r");
    float m = getMean(&ptr);
    printf("\nmean = %f", m);


    fclose(f);
}

void error(char* err)
{
    fprintf(stderr , "\n[ERROR] %s" , err);
    exit(1);
}

parametri decoceParameter(int argc , char* argv[])
{
    if(argc != 2)
    {
        error("numero di parametri errato!");
    }

    if(strlen(argv[1]) > 100)
    {
        error("nome del file troppo lungo! ");
    }

    parametri ptr;
    ptr.filename = argv[1];

    if(strcmp(ptr.filename + strlen(ptr.filename) - 4, ".txt") != 0)
    {
        error("Il file deve essere un file .txt!");
    }

    return ptr;

}

Nodo* readFile(FILE* f)
{
    Nodo* ptr = NULL;
    int n;
    char line[BUFFSIZE];
    while(fgets(line , BUFFSIZE, f) != NULL){
        n = atoi(line);
        push(n , &ptr);
    }
}

float getMean(Nodo** ptr)
{
    float m = 0;
    int counter = 0;
    int n = pop(ptr);

    while(n != -1)
    {   
        m+= n;
        counter++;
        n = pop(ptr);
    }
    m/=counter;
    return m;
}

void fillP(FILE* f,Nodo** ptr ,float m)
{
    int x;
    char line[BUFFSIZE];
    rewind(f);
    fgets(line, BUFFSIZE, f);
    push(atoi(line) , ptr);


    while(fgets(line , BUFFSIZE, f) != NULL){
        x = atoi(line);
        if(x > m)
        {
            push(x , ptr);
        }
        else
        {
            int y = pop(ptr); 
            push((x + y)/2 , ptr);
        }
    }

}

int* transferPTR(Nodo** ptr)
{
    int dim = stackSize(ptr);
    int * A = (int*)malloc(dim * sizeof(int));
    for(int i = 0; i < dim; i++)
    {
        A[i] = pop(ptr);
    }
    return A;
}

void bubbleSort(int* A, int n)
{
    int aux;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-n;j++)
        {
            if(A[j] > A[j+1])
            {
                aux = A[j + 1];
                A[j + 1] = A[j];
                A[j] = aux;
            }
        }
    }
}

void push(int val, Nodo** ptr)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->data = val;
    new_node->next = *ptr;
    *ptr = new_node;
}

int pop(Nodo **ptr)
{
    if(*ptr = NULL)
    {
        return -1;
    }
    else
    {
        Nodo* to_delete = *ptr;
        *ptr = to_delete->next;
        int n = to_delete->data;
        free(to_delete);
        return n; 
    }
}   

void printStack(Nodo* ptr)
{
    Nodo* curr = ptr;
    while(curr != curr)
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    }

    printf("NULL\n");
}

int StackSize(Nodo* ptr)
{
    int count = 0;
    Nodo* curr = ptr;
    while(curr != curr)
    {
        count++;
        curr = curr->next;
    }

    return count;
}




















    


    
//CICCIO è IL MIO EROE VOGLIO SUCCHIARGLI LE PALLE.