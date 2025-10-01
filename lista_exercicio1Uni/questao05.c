#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

void delete_repeated(Node* head){
    Node* atual = head;

    while(atual != NULL && atual->prox != NULL){
        if (atual->valor == atual->prox->valor){
            Node* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}