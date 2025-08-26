#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int n;
    struct Node *next;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL){
        printf("Error de alocamento de memoria.\n");
        exit(1);
    }

    new_node->n = value;
    new_node->next = NULL;
    return new_node;
}

void middle_insertion(Node** head, Node* new_node){
    if (*head == NULL){
        printf("Lista vazia\n");
        return;
    }

    Node* aux = *head;
    while (aux->next && aux->next->n < new_node->n){
        aux = aux->next;
    }

    new_node->next = aux->next;
    aux->next = new_node;

}
void print(Node** head){
    Node* aux = *head;
    printf("Lista: ");
    while (aux != NULL){
        printf("%d -> ", aux->n);
        aux = aux->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = create_node(10);
    Node* new_node = create_node(15);

    middle_insertion(&head, new_node);

    new_node = create_node(13);

    middle_insertion(&head, new_node);
    
    new_node = create_node(20);

    middle_insertion(&head, new_node);
    
    print(&head);

    Node* aux;
    while (head != NULL){
        aux = head;
        head = head->next;
        free(aux);
    }
    return 0;
}