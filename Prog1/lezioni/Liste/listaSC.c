#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

int main() {

    //Inizializzo dei nodi

    struct node* testa;
    struct node* nodo1 = NULL;
    struct node* nodo2 = NULL;
    struct node* nodo3 = NULL;

    //Alloco la memoria
    
    nodo1 = malloc(sizeof(struct node));
    nodo2 = malloc(sizeof(struct node));
    nodo3 = malloc(sizeof(struct node));

    //Assegno i valori
    
    nodo1 ->data = 17;
    nodo2 ->data = 86;
    nodo3 ->data = 53;

    //collego tra loro i nodi

    nodo1 -> next = nodo2;
    nodo2 -> next = nodo3;
    nodo3 -> next = NULL;
    testa = nodo1;
    
    return 0;
}