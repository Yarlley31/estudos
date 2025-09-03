/*
teria que ver o ultimo adicionado e entao removelo?
*/

/*
v = [ , , , , , ]
n = quantidade de elementos do vetor
vetor[n++] = value;
agora n = 1;
vetor[n++] = value;
n = 2;

vetor[n--]; // remover
n = 1;

último elemento 
stack[n-1];
*/


/*

fila com vetor com lista circular

dois indices 
i = inicio
j = fim
m = total de possiveis elementos

i++ % m (nao entendi direito) 

*/

/*

fila de prioridade

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct stack
{
    Node* top;
    int size;
} Stack;

Node* create(n){
    Node *new = (Node*) malloc(sizeof(Node));

    if(new == NULL){
        error();
    }

    new->value = n;
    new->next = NULL;

    return new;
}

void push_first(Node** head, Node** tail, int n){
    Node *new = create(n);

    *head = new;
    *tail = new;
    new->next = NULL;
}
void push(Node** tail,Node** aux_tail, int n){
    Node *new = create(n);

    *tail = aux_tail;
    (*aux_tail)->next = new;
    *aux_tail = new;
    new->next = NULL;
}

void delete(Node** tail){}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    Node* aux_tail = NULL;

    push_first(&head, &tail, 10);
    push(&tail, &aux_tail, 15);
    push(&tail, &aux_tail, 20);
}