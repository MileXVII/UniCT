#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char* err){
    fprintf(stderr, "\nERROR: %s", err);
    exit(1);
}

typedef struct{
    char *input_filename;
    char *output_filename;
}parametri;

typedef struct{
    char key[21];
    int vowels;
}dati;

typedef struct Nodo{
    dati* dato;
    struct Nodo *next;
    struct Nodo *prev;
}nodo;

parametri readInput(int argc , char* argv[]);
void buildArray(parametri ptr, dati* parola);
void countVowels(dati* parola);
void filter(dati* parola);
int buildList(dati* ptr , nodo **head);
void freeList(nodo *head);
void createSet(nodo **head);
void printList(nodo **head);
void save(parametri ptr , nodo **head);

int main(int argc , char* argv[]){

    printf("\n======punto A readInput======");
    parametri ptr = readInput(argc , argv);

    printf("\n======punto B buildArray , countVowels======");
    dati* Parola = calloc(200 , sizeof(dati)); //malloc(200 * sizeof(dati)) ma i campi dentro dati saranno inizializzati a 0
        if(Parola == NULL){
            error("Impossibile allocare 200 struct di dati");
        }

        buildArray(ptr, Parola);
        printf("\n======punto C filter======");
        filter(Parola);
        printf("\n======punto D buildList======");
        nodo *head = NULL;
        for(int i = 0; i < 200; i++){
            buildList(&Parola[i] , &head);
        }
        printf("\n======punto E createSet======");
        createSet(&head);
        printf("\n======punto F printList======");
        printList(&head);
        printf("\n======punto G save======");
        save(ptr , &head);

        free(Parola);
        freeList(head);
        return 0;

}

parametri readInput(int argc , char* argv[]){

        parametri ptr;

        if(argc != 3){
            error("Numero di paramatri passati non valido");
        }

        ptr.input_filename = argv[1];
        ptr.output_filename = argv[2];

        if (strcmp(ptr.input_filename + strlen(ptr.input_filename) - 4, ".txt") != 0) {
            error("Il file di input deve avere un'estensione .txt");
        }
        if (strcmp(ptr.output_filename + strlen(ptr.output_filename) - 4, ".txt") != 0) {
            error("Il file di output deve avere un'estensione .txt");
        }

        return ptr;
}

void buildArray(parametri ptr, dati* parola){
    FILE *file = fopen(ptr.input_filename , "r");
    if(file == NULL){
        error("Apertura del file input non riuscita");
    }

    for(int i = 0; i < 200; i++){
        fscanf(file , "%s" ,parola[i].key);
        countVowels(&parola[i]);
    }
    
    fclose(file);
}

void countVowels(dati* parola){
    int count = 0;
    for(int i = 0; i < strlen(parola->key); i++){
        if(strchr("aeiouAeiou", parola->key[i])){
            count++;
        }
    }
    parola->vowels = count;
}

void filter(dati* parola){

    for(int i = 0; i < 200; i++){
        for(int j = 0; parola[i].key[j] != '\0'; j++){

            if(strchr(",;:." , parola[i].key[j])){ 
                parola[i].key[j] = '\0'; //analizzando il file di input ho notato che la punteggiatura è presente solo alla fine della parola, da qui la mia logica di esecuzione
                break;
            }
        }
    }
}

int buildList(dati* ptr , nodo **head){
    /* ----LISTA *CIRCOLARE* DOPPIAMENTE CONCATENATA----*/

    //----CREAZIONE DEL NODO----

    nodo *new = malloc(sizeof(nodo));
    if(new == NULL){
        error("Allocazione dinamica di nuovo nodo non riuscita");
    }

    if(ptr->vowels < 0){
        free(new->dato);
        free(new);
        error("Vowels < 0");
    }

    new->dato = malloc(sizeof(dati));
    if(new->dato == NULL){
    error("Allocazione dinamica di dati non riuscita");
    }
    
    strcpy(new->dato->key , ptr->key);
    new->dato->vowels = ptr->vowels;
    new->prev = NULL;
    new->next = NULL;

    //----INSERIMENTO IN LISTA (CASO LISTA VUOTA)----
    if(*head == NULL){
        *head = new;
        new->next = new;  
        new->prev = new;  
        return 1;
    }

    //----INSERIMENTO IN LISTA IN TESTA(CASO LISTA ESISTENTE && VOWELS >=)----
    if(new->dato->vowels >= (*head)->dato->vowels){
    new->next = *head;
    new->prev = (*head)->prev;  // Puntatore al vecchio ultimo nodo
    (*head)->prev->next = new;  // Aggiorna il vecchio ultimo nodo
    (*head)->prev = new;        // Aggiorna il prev del vecchio head
    *head = new;                
    return 1; 
    }

    //----INSERIMENTO IN LISTA IN MEZZO O IN CODA (CASO LISTA ESISTENTE && VOWELS >=)----
    nodo *current = *head;
    while(current->next != *head && new->dato->vowels < current->next->dato->vowels){
        current = current->next;
    }

    new->next = current->next;
    new->prev = current;
    current->next->prev = new;
    current->next = new;

    
    if (new->next == *head) {
        (*head)->prev = new;    // Se il nuovo nodo è stato inserito in coda, aggiorna il puntatore circolare
    }

    return 1;
}

void createSet(nodo **head){

    if(*head == NULL){
        error("Lista Vuota");
    }

    nodo *current = *head;
    do{
        nodo *temp = current->next;

        while(temp != *head){
            if(strcmp(current->dato->key , temp->dato->key) == 0){

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if(temp == *head){
                    *head = temp->next;
                }

                free(temp->dato);
                free(temp);

                temp = current->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }while(current != *head);
}

void printList(nodo **head){

    if(head == NULL){
        error("lista vuota impossibile stampare");
    }

    nodo *current = *head;
    while(current->next != *head){
        printf("\n[%s] --> ", current->dato);
        current = current->next;
    }
    printf("%s ...\n", *head);
}

void save(parametri ptr , nodo **head){

    if(*head == NULL){
        error("Lista vuota, impossibile scrivere nel file");
    }

    FILE *file = fopen(ptr.output_filename , "w");

    if(file == NULL){
        printf("Apertura file output non riuscita");
    }

    nodo *current = *head;
    while(current->next != *head){
        fprintf(file , "\n%s , %d", current->dato->key , current->dato->vowels);
        current = current->next;
    }
    
    fclose(file);
}

void freeList(nodo *head) {
    nodo *current = head;
    nodo *nextNode;

    while (current != NULL) {
        nextNode = current->next; // Salva il riferimento al prossimo nodo
        free(current->dato);      // Libera la memoria allocata per dati
        free(current);            // Libera il nodo corrente
        current = nextNode;       // Passa al prossimo nodo
    }
}