#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

void remove_last(Node** head){
    if (*head == NULL){
        return;
    }
    if ((*head)->prox == NULL) {
        // só há um elemento
        free(*head);
        *head = NULL;
        return;
    }

    Node *atual = head;
    while(atual->prox->prox != NULL){
        atual = atual->prox;
    }
    
    free(atual->prox);
    atual->prox = NULL;
}