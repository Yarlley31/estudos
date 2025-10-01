#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

int soma_pares(Node* head){
    Node *atual = head;
    while(atual != NULL && atual->prox != NULL){
        int soma;
        if(atual->valor % 2 == 0){
            soma += atual->valor;
        atual = atual->prox;
        return soma;
    }
}