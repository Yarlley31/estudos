#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dados;
    struct Node *next;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL){
        printf("Error de alocamento de memoria.\n");
        exit(1);
    }

    new_node->dados = value;
    new_node->next = NULL;
    return new_node;
}

void middle_insertion(Node* head, int new_value, int reference_value){
    if (head == NULL){
        printf("Lista vazia ou nó de referencia nao encontrado.\n");
        return;
    }

    Node* current = head;
    while (current != NULL && current->dados != reference_value){
        current = current->next;
    }

    if (current != NULL){
        Node* new_node = create_node(new_value);
        new_node->next = current->next;
        current->next = new_node;
    } else {
        printf("Nó de referência %d nao encontrado.\n", reference_value);
    }

}
void print(Node* head){
    Node* current = head;
    printf("Lista: ");
    while (current != NULL){
        printf("%d -> ", current->dados);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = create_node(10);

              // inserir 20 apos 10
    middle_insertion(head, 20, 10);

             // inserir 15 apos 10 (que o valor de referencia)
    middle_insertion(head, 15, 10);

    middle_insertion(head, 18, 15);
    print(head); // Saida: 10 -> 15 -> 20 -> NULL

    Node* aux;
    while (head != NULL){
        aux = head;
        head = head->next;
        free(aux);
    }
    return 0;
}