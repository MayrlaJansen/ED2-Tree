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
AVLnode *remover_no_arvore(AVLnode *r, int x);
AVLnode *remover_no(AVLnode *r);
AVLnode *remover_2filhos(AVLnode *r);
AVLnode *remover_1filho_direita(AVLnode *r);
AVLnode *remover_1filho_esquerda(AVLnode *r);
AVLnode *remover_folha(AVLnode *r);
AVLnode *menor_no_arvore(AVLnode *r);
AVLnode *verifica_balanceamento(AVLnode *r);

#endif

 