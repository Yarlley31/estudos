#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int month, day, year;
} Date;

typedef struct{
    char name[50];
    Date birth;
} Person;

typedef struct Node
{
    Person p;
    struct Node *next;
} Node;

Person create_person(){
    Person p;

    printf("Digite o nome da pessoa e data de nascimento dd mm aaaa: ");
    scanf("%s %d %d %d", p.name, p.birth.day, p.birth.month, p.birth.year);
    return p;
}
int main(){


}