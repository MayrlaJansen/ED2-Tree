#ifndef _AVL_H_
#define _AVL_H_
#include "structs.h"

typedef struct _Node_{
    // struct _data_ *data;
    int info;
    int height;
    struct _Node_ *left;
    struct _Node_ *right;
} AVLnode;

AVLnode* insert_AVLnode(AVLnode* root,int info);
int Query(AVLnode* root,int str,int* passos);
void Destroy(AVLnode *t);
void printarTree(AVLnode *root);

#endif

 