#include <stdio.h>
#include <stdlib.h>

//definizione della struttura del nodo
struct node{
    int data;
    struct node* next;
};

//dichiarazione delle funzioni
void list_insert(struct node** , int);
void list_display(struct node*);
int list_search(struct node* , int);
void list_delete(struct node** , int);

int main() {

    //Inizializzo dei nodi

    struct node* testa = NULL; //inizializzo testa
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

    //stampo la lista
    list_display(testa);

    int n;
    printf("inserisci un nuovo numero: \n");
    scanf("%d", &n);

    //inserisco un nuovo nodo in testa
    list_insert(&testa , n);
    
    //stampo la lista aggiornata
    list_display(testa);

    int nodoCercato;

    printf("Inserisci un nodo da cercare: \n");
    scanf("%d", &nodoCercato);

    //cerco un nodo nella lista
    if(list_search(testa , nodoCercato))
    {
        printf("il nodo %d e' presente nella lista\n",nodoCercato);
    }
    else{
        printf("il nodo %d non e' presente nella lista\n",nodoCercato);
        }

    printf("Inserisci un nodo da eliminare: \n");
    scanf("%d", &nodoCercato);

    list_delete(&testa , nodoCercato);

    list_display(testa);



    return 0;
}

//funzione per inserire un nodo in testa
void list_insert(struct node** head , int new_data)
{
    //Alloco la memoria per il nuovo nodo e preparo i suoi campi
    struct node* nuovo = (struct node*)malloc(sizeof(struct node));
    if(nuovo == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        exit(0);
    }

    nuovo -> data = new_data;
    nuovo -> next = (*head);

    (*head) = nuovo;
}

//funzione per stampare la lista
void list_display(struct node *p){
    printf("\n");

    while (p != NULL) {
        printf("\n|%d| -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

//funzione per cercare un nodo
int list_search(struct node* corrente, int ricercato){

    //struct node* corrente = *head;

    while (corrente != NULL) {
        if (corrente->data == ricercato) 
         return 1;

         corrente = corrente -> next;
    }

    return 0;
}

//funzione per eliminare un nodo
void list_delete(struct node** head, int key){
    struct node *tmp = *head;
    struct node *prev = NULL;

    //sto eliminando la testa
    if(tmp != NULL && tmp->data == key){
        *head = tmp->next;
        free(tmp);
        return;
    }

    //ricerca il nodo da eliminare, tenendo traccia del precedente (per poter modificare prev->next)
    while(tmp != NULL && tmp->data != key){
        prev = tmp;
        tmp = tmp->next;
    }

    //nessun nodo ha come 'dato' la 'chiave'
    if(tmp == NULL) return;

    //modifica il next dal nodo precedente e quello eliminato
    prev->next = tmp->next;
    free(tmp);
}
