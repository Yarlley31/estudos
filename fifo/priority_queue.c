#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int priority; // 1 maior prioridade, 2 menos, 3 menos, ...
    struct node* next;
} Node;

Node* create_node(int value, int priority){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        printf("Erro de alomanento.\n");
        EXIT_FAILURE;
    }

    new_node->value = value;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

void priority_insertion(Node** head, int value, int priority){
    Node* new_node = create_node(value, priority);

    // caso 1: lista vazia ou a prioridade do novo elemento é maior que a prioridade da cabeça
    if (*head == NULL || priority < (*head)->priority){ // se lista varia ou prioridade do novo elemento é menor do que prioridade do primeiro elemento
        new_node->next = *head;
        *head = new_node;
    } else {
        // caso 2: procurar o local certo pra inserir o elemento
        Node* aux = *head;
        while (aux->next != NULL && priority >= aux->next->priority){ // enquanto aux next diferente de NULL e prioridade do novo elemento é maior doq a prioridade do aux->next
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
    }
}

void print(Node* head){
    if (head == NULL){
        printf("A fila está vazia.\n");
    } else {
        Node* aux = head;
        while (aux != NULL)
        {
            printf("P%d, %d, -> ", aux->priority, aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
    }

}

void remove_higher_priority(Node** head){
    if (*head == NULL)
        printf("A fila já está vazia.\n");
    

    Node* to_be_removed = *head;
    *head = (*head)->next;
    free(to_be_removed);
}

void free_total(Node** head){
    if (*head == NULL){
        printf("A fila já está vazia.\n");
        return;
    }
    Node* aux;
    while (*head != NULL) {
        aux = *head;
        *head = aux->next;
        free(aux);
    }
}

int main(){
    Node* queue = NULL;
    priority_insertion(&queue, 200, 3);
    priority_insertion(&queue, 100, 2);
    priority_insertion(&queue, 250, 4);
    priority_insertion(&queue, 500, 4); 
    
    print(queue);
    remove_higher_priority(&queue);
    print(queue);

    priority_insertion(&queue, 50, 1);
    print(queue);

    free_total(&queue);

    return 0;
}