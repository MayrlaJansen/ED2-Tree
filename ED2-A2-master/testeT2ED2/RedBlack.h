#ifndef _REDBLACK_H_
#define _REDBLACK_H_
#include "structs.h"

    typedef struct _RBNode_{
        int color;
        // struct _data_ *data;
        int info;
        struct _RBNode_ *left, *right, *dad;
    } RBnode;

    extern void RB_Insert(RBnode** root, int info);
    int Query(RBnode* root,int str,int* passos);
    void printarTree(RBnode *root);
    RBnode* minimoVP(RBnode *noh);
    RBnode* sucessorVP(RBnode *noh);
    RBnode *arvRN_busca (RBnode *p, int k) ;
    void arvRN_remove (RBnode *r, RBnode *nodok);
    RBnode *arvRN_sucessor (RBnode *p);
    // void RBDestroy(RBnode *t);
#endif 
