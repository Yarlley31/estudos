#include <stdio.h>
#include <stdlib.h>

#define FLAG_EMPTY 0
#define FLAG_DELETED -1

typedef struct hash {
    int* hash_table;
    int n;       // número de elementos inseridos
    int size;    // tamanho total da tabela
} Hash;

int hashcode(int dado, int size) {
    return (dado * 5 + 3) % size;
}


void insert(Hash* hash, int dado) {
    // calcular taxa de ocupação
    if ((float)hash->n / hash->size > 0.7) {
        rehashing(hash);
    }
    
    int index = hashcode(dado, hash->size);
    while (hash->hash_table[index] != FLAG_EMPTY && hash->hash_table[index] != FLAG_DELETED) {
        index = (index + 1) % hash->size;  // sondagem linears
    }
    
    hash->hash_table[index] = dado;
    hash->n++;
}

void rehashing(Hash *hash){
    int i;
    int old_size = hash->size;
    int* old_table =  hash->hash_table;

    hash->size = old_size * 2;
    hash->hash_table = (int*) calloc(hash->size, sizeof(int));
    hash->n = 0;

    for(i = 0; i < old_size; i++){
        if(old_table[i] != FLAG_EMPTY && old_table[i] != FLAG_DELETED){
            insert(hash, old_table[i]);
        }
    }

    free(old_table);
}

int delete(Hash* hash, int dado){
    int index = hashcode(dado, hash->size);
    int start = index;

    while(hash->hash_table[index] != FLAG_EMPTY){
        if (hash->hash_table[index] == dado){
            hash->hash_table[index] = FLAG_DELETED;
            hash->n--;
            return 1;
        }
        
        index = (index + 1) % hash->size;
        if (index == start)
            break;
    }
    return -1;
}

int search(Hash *hash, int dado){
    int index = hashcode(dado, hash->size);
    int start = index;

    while (hash->hash_table[index] != FLAG_EMPTY){
        if (hash->hash_table[index] == dado){
            return index;
        }

        index = (index + 1) % hash->size;
        if (index == start){
            break;
        }
    }
    return -1;
}

void print_table(Hash* hash) {
    printf("\n--- Tabela Hash ---\n");
    int i;
    for (i = 0; i < hash->size; i++) {
        if (hash->hash_table[i] == FLAG_EMPTY) {
            printf("[%d]: (vazio)\n", i);
        } else if (hash->hash_table[i] == FLAG_DELETED) {
            printf("[%d]: (removido)\n", i);
        } else {
            printf("[%d]: %d\n", i, hash->hash_table[i]);
        }
    }
}

void init(Hash* hash) {
    hash->size = 10;
    hash->n = 0;
    hash->hash_table = (int*) calloc(hash->size, sizeof(int));
    // calloc zera a tabela, então FLAG_EMPTY = 0 funciona
}

int main() {
    Hash hash;
    init(&hash);

    insert(&hash, 15);
    insert(&hash, 25);
    insert(&hash, 35);
    insert(&hash, 75);
    insert(&hash, 54);
    insert(&hash, 83);
    insert(&hash, 96);
    insert(&hash, 27);
    insert(&hash, 31);

    
    int i; 
    for (i = 0; i < hash.size; i++) { 
        printf("[%d]: %d\n", i, hash.hash_table[i]); 
    }

    // search
    int dado_procurado = 96;
    int pos = search(&hash, dado_procurado);
    if (pos != -1){
        printf("Valor %d encontrado no index: %d\n",dado_procurado, pos);
    } else {
        printf("Valor %d não encontrado.\n", dado_procurado);
    }

        printf("\nRemovendo valor 75...\n");
    if (delete(&hash, 75)) {
        printf("Valor 75 removido com sucesso.\n");
    } else {
        printf("Valor 75 não encontrado.\n");
    }

    for (i = 0; i < hash.size; i++){ 
        printf("[%d]: %d\n", i, hash.hash_table[i]); 
    }

    free(hash.hash_table);

    return 0;
}