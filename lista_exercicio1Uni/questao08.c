#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

void return_position(Node* head, int n){
    int position = 1;

    while(head){
        if(head->valor == n){
            return position;
        } else{
            head = head->prox;
            position++;
        }
    }
    return position;
}