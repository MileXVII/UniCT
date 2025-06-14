#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char* input_filename;
    int n;
}parametri;

typedef struct Nodo{
    char dato[31];
    struct Nodo *next;
    struct Nodo *prev;
}nodo;

void error(char* err){
    fprintf(stderr, "\nERRORE: %s", err);
    exit(1);
}

parametri readInput(int argc, char* argv[]);
int insertWord(char *dato, nodo **head);
void buildList(parametri ptr, nodo **head);
void freeList(nodo *head);
void printList(nodo *head);
void elab(parametri ptr , nodo *head);

int main(int argc , char* argv[]){

        printf("\n======Punto A readInput======\n");
        parametri ptr = readInput(argc , argv);
        printf("\nparametri passati: %s , %d", ptr.input_filename , ptr.n);
        printf("\n======Punto B buildList,Insert Word======\n");
        nodo* head = NULL;
        buildList(ptr , &head);
        printf("\n======Punto C printList======\n");
        nodo* temp = head;
        while (temp != NULL) {
        printList(temp);
        temp = temp->next;
        }
        printf("\n======Punto D elab======\n");
        elab(ptr , head);

        freeList(head);
        
        return 0;
}

parametri readInput(int argc, char* argv[]){
    
    parametri ptr;
    if(argc!= 3){
        error("Il numero di parametri passati non è corretto");
    }

    ptr.input_filename = argv[1];
    ptr.n = atoi(argv[2]);

    if(strcmp(ptr.input_filename + strlen(ptr.input_filename) - 4 , ".txt") != 0){
        error("Il file di input non ha l'estensione .txt");
    }

    if(ptr.n < 7 || ptr.n > 13){
        error("Il numero n passato non è compreso tra 7 e 13");
    }    
    
    return ptr;
}

int insertWord(char *dato, nodo **head) {
    nodo *new = malloc(sizeof(nodo));
    if (new == NULL) {
        error("Allocazione di memori del nodo non riuscita");
    }

    strcpy(new->dato, dato);
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        return 1; 
    }

    // Caso 2: inserimento in testa (il nuovo dato è minore del primo elemento)
    if (strcmp(dato, (*head)->dato) < 0) {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return 1; 
    }

    // Caso 3: inserimento in mezzo o in coda
    nodo *current = *head;
    while (current->next != NULL && strcmp(current->next->dato, dato) < 0) {
        current = current->next;
    }

    // Inserisci il nuovo nodo dopo `current`
    new->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new;
    }
    current->next = new;
    new->prev = current;

    return 1; 
}


void buildList(parametri ptr, nodo **head) {
    FILE *file = fopen(ptr.input_filename , "r");
    if(file == NULL){
        error("Impossibile aprire il file in input");
    }

    char temp[31];
    while(fscanf(file , "%s" , temp) != EOF){
        insertWord(temp , head);
    }

    fclose(file);
}

void printList(nodo *head){
    if(head == NULL){
        error("Lista vuota");
    }
        
        printf("\n|%s| -> ", head->dato);
        head = head->next;

}

void elab(parametri ptr , nodo *head){
    while(head->next != NULL){
    if(strlen(head->dato) >= ptr.n){
        printList(head);
        head = head->next;
    }
    else
    {
        head = head->next;
    }

    }
} 



void freeList(nodo *head) {
    nodo *current = head;
    nodo *nextNode;

    while (current != NULL) {
        nextNode = current->next; // Salva il riferimento al prossimo nodo
        free(current);            // Libera il nodo corrente
        current = nextNode;       // Passa al prossimo nodo
    }
}