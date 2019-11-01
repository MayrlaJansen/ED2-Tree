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
            return root->info;
        }else if(value > root->info){
            return QueryB(root->right, str, &*passos);
        }else{
            return QueryB(root->left, str, &*passos);
        }
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


void printarTree(BinariaNode *root){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita 
    if(root != NULL) {
	  printarTree(root->left);
	  printf("%i\n", root->info);
	  printarTree(root->right);
    }
}