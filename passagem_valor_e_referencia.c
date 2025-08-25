#include <stdio.h>

// por referencia
void dobra(int *n){
    // *n é o elemento apontado por n 
    *n = (*n) * 2;
    printf("Endereço de n: %p\n", n);
    printf("Conteudo apontado por n: %d\n", *n);
}

int main(){
    int num1 = 10;
    dobra(&num1);
    printf("Valor de num1: %d\n", num1);
    
    return 0;
}