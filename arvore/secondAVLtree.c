#include <stdio.h>
#include <stdlib.h>

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

Tree *insert(Tree* root, int value){
    if(!root)
        return new_leaf(value);
    
    if(value < root->value){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

Tree* search(Tree* root, int value){
    if(root == NULL || root->value == value)
        return root;
    
    if(value < root->value){
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }

    return root;
}

void preOrder(Tree* root){
    if(!root) 
        return;

    printf("%d\n", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Tree* root){
    if(!root)
        return;
    
    inOrder(root->left);
    printf("%d\n", root->value);
    inOrder(root->right);
}

void posOrder(Tree* root){
    if(!root)
        return;
    
    posOrder(root->left);
    posOrder(root->right);
    printf("%d\n", root->value);
}