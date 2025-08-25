#include <stdio.h>
#include <stdlib.h>

void error(){
    printf("Erro de alocacao de memoria.\n");
    exit(1);
}

typedef struct node
{
    int n;
    struct node* next;
} Node;

Node *create(int value){
    Node *new = (Node*) malloc(sizeof(Node));

    if(new == NULL){
        error();
    }

    new-> n = value;
    new-> next = NULL;

    return new;
}

void push_front(Node** head, int value){
    Node* new = create(value);

    new-> next = *head;
    *head = new;
}

void print(Node* head){
    Node* current = head;
    printf("Lista: ");
    while (current != NULL){
        printf("%d -> ", current->n);
        current = current->next;
    }
    printf("NULL\n");
}


int main(){
    Node* head = NULL;

    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);

    print(head);

}