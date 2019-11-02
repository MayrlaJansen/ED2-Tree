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
//Rota��o a right
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
            return 1;
        }else if(value > root->info){
            return Query(root->right, str, &*passos);
        }else{
            return Query(root->left, str, &*passos);
        }
        *passos = *passos + 1;
        return 0;
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
void printarTree(RBnode *root){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela right 
    if(root != NULL) {
        
	  printarTree(root->left);
	  printf("%i\n", root->info);
	  printarTree(root->right);
    }
}

void arvRN_remove (RBnode *r, RBnode *nodok) { 
    RBnode *nodoRem, *filho;
    if (nodok == NULL)
        return;
    if (nodok->left == NULL || nodok->right == NULL)
    /* se nodok tem 0 ou 1 filho, remove nodok */
        nodoRem = nodok;                               
    else                           /* senão remove o Sucessor */
        nodoRem = arvRN_sucessor (nodok); /* neste caso o nodoRem não tem filho left */  
    if (nodoRem->left != NULL)
        filho = nodoRem->left;
    else
        filho = nodoRem->right;
    filho->dad = nodoRem->dad;
    if (nodoRem->dad == NULL)
        r = filho;
    else if (nodoRem == nodoRem->dad->left)
        nodoRem->dad->left = filho;
    else
        nodoRem->dad->right = filho;
    if (nodok != nodoRem) /* copia chave e dados do nodoRem para nodok */
        nodok->info = nodoRem->info;
    if (nodoRem == r){
        r = NULL;
        return;
    }
    free(nodoRem);
    if (nodoRem->color == 0)
        fix_insert (&r, filho);
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Busca o nodo que contem a chave k                                          */ 
/*----------------------------------------------------------------------------*/
RBnode *arvRN_busca (RBnode *p, int k) {
    RBnode *aux = NULL;
    if (p == NULL)
        return aux;
    if (p->info == k)        
        return p;
    else if (k < p->info)
        return arvRN_busca (p->left, k);
    else
        return arvRN_busca (p->right, k);
}
RBnode *arvRN_sucessor (RBnode *p) {
    RBnode *aux,*a;
    a = NULL;
    if (p->right == NULL)
        return a;
    aux = p->right;
    while (aux->left != NULL){
        aux = aux->left;
    }
    return aux;
}