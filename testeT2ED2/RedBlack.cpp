#include "RedBlack.h"

//Rota��o a esquerda
void rightRotate(RBnode** root, RBnode* x){
    RBnode* y = x->left;
    x->left = y->right;
    if(y->right != NULL)
        y->right->dad = x;
    y->dad = x->dad;
    if (x->dad == NULL){
        *root = y;
    }else{
        if(x == x->dad->right)
            x->dad->right = y;
        else
            x->dad->left = y;
    }
    y->right = x;
    x->dad = y;
}
//Rota��o a direita
void leftRotate(RBnode** root,RBnode* x){
    RBnode* y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->dad = x;
    y->dad = x->dad;
    if(x->dad == NULL)
        *root = y;
    else{
        if(x == x->dad->left)
            x->dad->left = y;
        else
            x->dad->right = y;
    }
    y->left = x;
    x->dad = y; 
}

//color 1-red 0-black
void fix_insert(RBnode **root, RBnode *node){
    RBnode* z = node;
    while((*root != z) && (z->dad->color==1)){
        if(z->dad == z->dad->dad->left){
            RBnode* y = z->dad->dad->right;
            /*Caso 1: Um n� x est� sendo inserido, e seu tio �
            vermelho ent�o � necess�rio recolorir o pai, o tio
            o av�*/
            if((y!=NULL) && (y->color == 1)){
                z->dad->color = 0;
                y->color = 0;
                z->dad->dad->color = 1;
                z = z->dad->dad;
            }else{
                if(z == z->dad->right){
                    /*Caso 2:irm�o preto e pai vermelho*/
                    z = z->dad;
                    leftRotate(&*root,z);
                }
                /*Caso 3:pai vermelho, irm�o preto, av� preto*/
                z->dad->color = 0;
                z->dad->dad->color = 1;
                rightRotate(&*root,z->dad->dad);
            }
        }else{
            RBnode* y = z->dad->dad->left;
            if((y!=NULL) && (y->color == 1)){
                /*caso 4*/
                z->dad->color = 0;
                y->color = 0;
                z->dad->dad->color = 1;
                z = z->dad->dad;
            }else{
                /*Caso 5:*/
                if(z == z->dad->left){
                    z = z->dad;
                    rightRotate(&*root,z);
                }
                /*Caso 6:pai vermelho, av� preto, tio preto*/
                z->dad->color = 0;//pai fica preto
                z->dad->dad->color = 1;//av� fica vermelho
                leftRotate(&*root, z->dad->dad);//gera uma rota��o a esquerda
            }
        }
    }
}

void RB_Insert(RBnode** root, int info){
    RBnode* y = NULL;
    RBnode* x = *root;
    while(x != NULL){
        y = x;
        if(info < x->info)
            x = x->left;
        else
            x = x->right;
    }
    RBnode* newnode = new RBnode[1];
    if(newnode != NULL){
        newnode->info = info;
        newnode->color = 1;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->dad = y;
    }
    if(y == NULL){
        *root = newnode;
    }else{
        if(info < y->info)
            y->left = newnode;
        else
            y->right = newnode;
    }
    fix_insert(&*root, newnode);
    (*root)->color = 0;
}

//Query
int Query(RBnode* root,int str,int* passos){
    int value = str;
    if(root != NULL){
        if(root->info ==  value){
            // *aux = (Data*)root->info;
            return root->info;
        }else if(value > root->info){
            return Query(root->right, str, &*passos);
        }else{
            return Query(root->left, str, &*passos);
        }
    }
    *passos = *passos + 1;
    return 0;
}
// //Destruir
// void RBDestroy(RBnode *t){
//     if(t != NULL){
//         RBDestroy(t->left);
//         RBDestroy(t->right);
//         t->data->linhas.clear();
//         t->data->ocorrencias.clear();
//         delete[]t->data;
//         delete[]t;
//     }
// }
