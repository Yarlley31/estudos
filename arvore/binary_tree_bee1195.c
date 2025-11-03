#include <stdio.h>
#include <stdlib.h>


// creating

typedef struct tree{
    int value;
    struct tree *left;
    struct tree *right;
} Tree;

Tree *new_leaf(int value){
    Tree *leaf = (Tree*)malloc(sizeof(Tree));

    leaf->value = value;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

// inserting

struct tree *insert(Tree *root, int value){
    if(!root){
        return new_leaf(value);
    }
    if(value < root->value){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// search

Tree *search(Tree* root, int value){
    if(root == NULL || root->value == value){
        return root;
    }

    if(value < root->value)
        return search(root->left, value);
    else 
        return search(root->right, value);

    return root;
}

// printing

void preOrder(Tree *root, int *first){
    if (!root) return;
    if (*first) *first = 0;
    else printf(" ");
    printf("%d", root->value);
    preOrder(root->left, first);
    preOrder(root->right, first);
}

void inOrder(Tree *root, int *first) {
    if (!root) return;
    inOrder(root->left, first);
    if (*first) *first = 0;
    else printf(" ");
    printf("%d", root->value);
    inOrder(root->right, first);
}

void posOrder(Tree *root, int *first) {
    if (!root) return;
    posOrder(root->left, first);
    posOrder(root->right, first);
    if (*first) *first = 0;
    else printf(" ");
    printf("%d", root->value);
}

void freeTree(Tree *root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {

    Tree *root = NULL;

    int i, j, c;
    scanf("%d", &c);
    
    for(i = 0; i < c; i++){
        int num_elements, key;
        scanf("%d", &num_elements);

        Tree *root = NULL;

        for(j = 0; j < num_elements; j++){
            scanf("%d", &key);
            root = insert(root, key);
        }

        printf("Case %d:\n", i+1);

        int first = 1;
        printf("Pre.: ");
        preOrder(root, &first);
        printf("\n");

        first = 1;
        printf("In..: ");
        inOrder(root, &first);
        printf("\n");


        first = 1;
        printf("Post: ");
        posOrder(root, &first);
        printf("\n\n");


        freeTree(root);
    }

    return 0;
}