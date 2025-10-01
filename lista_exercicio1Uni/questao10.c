#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;


void invert_list(Node** head){
    if(*head == NULL && (*head)->prox){
        return;
    } else {
        Node* aux = head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        Node *tail = aux;
        tail = head;
        head = aux;
        aux = tail->prox;
        while (aux->prox != head){
            
        }
    }
}