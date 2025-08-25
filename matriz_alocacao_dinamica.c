#include <stdio.h>
#include <stdlib.h>

void error(){
    printf("Erro de memoria\n");
    exit(1);
}

void create(int*** mat, int rows, int columns){
    int i;
    *mat = (int **) malloc(rows * sizeof(int *));
    if (*mat == NULL){
        error();
    }

    for(i = 0; i < rows; i++){  
        (*mat)[i] = (int*) malloc(columns * sizeof(int));
        if ((*mat)[i] == NULL)
        {
            error();
            while(i--){
                free((*mat)[i]);
            }
            *mat = NULL;
            return;
        }
        
    }
    printf("Matriz criada com sucesso!\n");
}

void write(int** mat, int rows, int columns){
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            mat[i][j] = i + j;
}

void print(int** mat, int rows, int columns){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++)
            printf("%d", mat[i][j]);
        printf("\n");
    }    
}

void clear(int*** mat, int rows){
    int i;
    if (*mat == NULL){
        return;
    }

    for (i = 0; i < rows; i++){
        free((*mat)[i]);
    }

    free((*mat));
}


int main(){
    int** mat;
    int rows = 4, columns = 6;

    create(&mat, rows, columns);
    if (mat != NULL){
        write(mat, rows, columns);
        print(mat, rows, columns);
        clear(&mat, rows);
    }

    return 0;
}