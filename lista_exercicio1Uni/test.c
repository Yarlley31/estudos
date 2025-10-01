#include <stdio.h>
int main(){
int a;
int valor = 25;
int *p;
p = &valor;
a = 10;
a = a + (*p);
printf("O valor de a eh: %d", a);
return 0;
}