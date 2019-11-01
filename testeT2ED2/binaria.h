#ifndef _BINARIA_H_
#define _BINARIA_H_ 
#include "structs.h"

    typedef struct _BNode_{
        // struct _data_ *data;
        int info;
        struct _BNode_ *left;
        struct _BNode_ *right;
    } BinariaNode;

    BinariaNode* insert_BinariaNode (BinariaNode* root,int info);
    int QueryB(BinariaNode* root,int str,int* passos);
    void Destroy(BinariaNode *t);
    void printarTree(BinariaNode *root);
    int treeIsEmpty(BinariaNode* root);

#endif 