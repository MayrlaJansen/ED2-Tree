#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include "binaria.h"
using namespace std;

BinariaNode* insert_BinariaNode(BinariaNode* root,int info){
   if(root == NULL){
      root = (BinariaNode *)malloc(sizeof(BinariaNode));
      root->info = info;
      root->left = NULL;
      root->right= NULL;
      return root;
   }
   if(info < root->info){
    //   printf("%d inserido na esquerda",root->info);
      root->left=insert_BinariaNode(root->left, info);
      return root;
   }
   if(info > root->info){
    //   printf("%d inserido na direita", root->info);
      root->right=insert_BinariaNode(root->right,info);
      return root;
   }
   else
      return NULL;
}

int QueryB(BinariaNode* root,int str,int* passos){
    int value = str;
    if(root != NULL){
        if(root->info ==  value){
            // *aux = (Data*)root->info;
            return 1;
        }else if(value > root->info){
            return QueryB(root->right, str, &*passos);
        }else{
            return QueryB(root->left, str, &*passos);
        }
        *passos = *passos + 1;
        return 0;
    }
    *passos = *passos + 1;
    return 0;
}

// void Destroy(BinariaNode *t){
//     if(t != NULL){
//         Destroy(t->left);
//         Destroy(t->right);
//         t->data->linhas.clear();
//         t->data->ocorrencias.clear();
//         delete[]t->data;
//         delete[]t;
//     }
// }
void removeB (BinariaNode *pt, int info)
    { BinariaNode* pai, *ptaux;
    /* a busca */
    do{ pai = pt ;
    if (info < pt->info) pt = pt ->left ;
    else if ( info > pt-> info) pt = pt->right;
    } while((pt != NULL) && (pt->info != info));
    if (pt != NULL){
        if (pt != NULL){ /* ok, encontrou o info na ABB */
/* se é um nó interno com duas subárvores vazias */
    if ((pt-> left != NULL) && (pt->right != NULL)){
    ptaux = pt;
    pai = pt; pt = pt->right;
    while (pt->left != NULL) { /* acha o imediatamente maior */
    pai = pt;
    pt = pt->left;
    }
    /* troca o info do nó a ser retirado pelo imediatamente maior */
    ptaux->info = pt->info;
    } 
    if (pt != NULL){ /* ok, encontrou o info na ABB */
    /* se é um nó interno com duas subárvores vazias */
    if ((pt->left != NULL) && (pt-> right == NULL)){
    /* só tem o filho left */
    if (pai->left ==pt) pai->left = pt->left;
    else pai->right = pt->left;
    } else if ((pt->left == NULL) && (pt-> right != NULL)){
    /* só tem o filho righteito */
    if (pai->left ==pt) pai->left = pt->right;
    else pai->right = pt->right;
    } else{/* então é folha */
    if (pai->left ==pt) pai->left = NULL;
    else pai->right = NULL;
    }
    free (pt);
    } 
        }
    }
    }

void printarTree(BinariaNode *root){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita 
    if(root != NULL) {
	  printarTree(root->left);
	  printf("%i\n", root->info);
	  printarTree(root->right);
    }
}