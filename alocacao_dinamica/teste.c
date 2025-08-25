#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    int i, qntd_elements;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qntd_elements);


    p = (int *)(malloc(qntd_elements * sizeof(int)));

    if (p == NULL){
        printf("\nErro de alocamento de memória!");
        system("pause");
        return EXIT_FAILURE;
    }
    printf("\n");
    // recebendo os valores para o vetor
    for (i = 0; i < qntd_elements; i++){
        printf("Digite o elemento do indice [%d]: ", i);
        scanf("%d", &p[i]);
    }
    
    printf("\n");

    // mostrando os valores do vetor
    for (i = 0; i < qntd_elements; i++){
        printf("Valor armazenado no indice [%d]: %d\n", i, p[i]);
    }

    printf("\n");

    
    free(p);
    system("pause");
    return 0;
}