#include <stdio.h>

void swap(int* v, int m, int r) {
    int aux = v[m];
    v[m] = v[r];
    v[r] = aux;
}

void quicksort(int* v, int l, int r){
    if(l >= r){
        return;
    }

    int m = (l + r) / 2;
    int pivo = v[m];
    swap(v, m, r);  // Move pivot to end

    int i = l;
    int j = r - 1;

    while(i <= j){
        while(i <= j && v[i] < pivo){
            i++;
        }
        while(i <= j && v[j] > pivo){
            j--;
        }
        if(i <= j){
            swap(v, i, j);
            i++;
            j--;
        }
    }

    swap(v, i, r);  // Put pivot in the correct position

    quicksort(v, l, j);       // Left partition
    quicksort(v, i + 1, r);   // Right partition (skip pivot)
}

int main(){
    int v[10] = {5,1,8,6,4,9,7,3,2,0};
    int i;

    printf("Before: \n");
    for(i = 0; i < 10; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }

    quicksort(v, 0, 9);  // Call QuickSort on full array

    printf("After: \n");
    for(i = 0; i < 10; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}