#include "AVL.h"
using namespace std;

int Rdupla = 0;
int rSimples = 0;
int nVisitados = 0;

//Calcule altura de um n�
int height_node(struct _Node_* node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}
//Calcule o fator de balanceamento de um n�
int fatorBalanceamento_node(struct _Node_* node){
    int valor = (height_node(node->right))-(height_node(node->left));
    return valor;
}
//Calcula o maior valor
int maior(int x, int y){
    if(x > y) 
        return x;
    else
        return y;
}
//Rota��o a leftuerda
AVLnode* RotationLL(AVLnode* root){
    AVLnode*node;
    node = root->left;
    root->left = node->right;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->left),height_node(root)) + 1;
    root = node;
    return root;
}
//Rota��o a direita
AVLnode* RotationRR(AVLnode* root){
    AVLnode* node;
    node = root->right;
    root->right = node->left;
    root->height = maior(height_node(root->left),height_node(root->right)) + 1;
    node->height = maior(height_node(node->right),height_node(root)) + 1;
    root = node;
    return root;
}
//Rota��o dupla a esquerda
AVLnode* RotationLR(AVLnode* root){
    root->left = RotationRR(root->left);
    root = RotationLL(root);
    return root;
}
//Rota��o dupla a direita
AVLnode* RotationRL(AVLnode* root){
    root->right = RotationLL(root->right);
    root = RotationRR(root);
    return root;
}
//Insert AVLtree
AVLnode* insert_AVLnode(AVLnode* root,int info){
    //�rvore vazia ou n� folha
    if(root == NULL){
        AVLnode* novo;
        novo = new AVLnode[1];
        if(novo == NULL)
            return NULL;
        novo->info = info;
        novo->height = 0;
        novo->left = NULL;
        novo->right = NULL;
        return novo; 
    }

    AVLnode* current = root;

    /*Balan�eamento*/
    if(info < current->info){
        current->left = insert_AVLnode(current->left, info);
        if(current->left != NULL){
            if(fatorBalanceamento_node(current) <= -2){
                if(info < current->left->info)
                    root = RotationLL(root);
                else
                    root = RotationLR(root);
            }
        }
        return root;
    }else{
        if(info > current->info){
            current->right = insert_AVLnode(current->right, info);
            if(current->right != NULL){
                if(fatorBalanceamento_node(current) >= 2){
                    if(info > current->right->info)
                        root = RotationRR(root);
                    else
                        root = RotationRL(root);
                }
            }
        }
        return root;
    }
    return NULL;
}
//Query
int Query(AVLnode* root,int str,int* passos){
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
//Destruir
// void Destroy(AVLnode *t){
//     if(t != NULL){
//         Destroy(t->left);
//         Destroy(t->right);
//         // t->data->linhas.clear();
//         // t->data->ocorrencias.clear();
//         delete[]t->info;
//         delete[]t;
//     }
// }

void printarTree(AVLnode *root){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita 
    if(root != NULL) {
	  printarTree(root->left);
	  printf("%i\n", root->info);
	  printarTree(root->right);
    }
}
 
//Funçães que retorna o endereço do menor nó da árvore.
AVLnode *menor_no_arvore(AVLnode *r) {
    AVLnode *aux = r;
    while (aux->left != NULL) {  //Procurar o nó mais a esquerda (menor nó da árvore).
        //printf("aux: %d\n", aux->n);
        aux = aux->right;
    }
    //printf("aux: %d\n", aux->n);
    return aux;                 //Retornar o endereço do menor nó da árvore.
}

//Função que remove um nó que é folha (não possui filhos).
AVLnode *remover_folha(AVLnode *r) {
    // printf("\nA folha %d foi removida com sucesso!\n", r->n);
    //getch();
    free(r);
    return NULL;
}

AVLnode *remover_1filho_esquerda(AVLnode *r) {
    AVLnode *aux = r->left;
    // printf("\n numero %d foi removido com sucesso!\n", r->n);
    free(r);
    return aux;
}

AVLnode *remover_1filho_direita(AVLnode *r) {
    AVLnode *aux = r->right;
    // printf("\n numero %d foi removido com sucesso!\n", r->n);
    free(r);
    return aux;
}

AVLnode *remover_2filhos(AVLnode *r) {
    AVLnode *aux;
    int x;
    aux = menor_no_arvore(r->right);  //auxiliar recebe o endereço do menor nó da árvore.
    //printf("aux: %d\n", aux->n);
    x = aux->info;                     //guardar o valor do auxiliar em uma variável x.
    r = remover_no_arvore(r,x);     //remover da árvore o nó que substituirá o nó com 2 filhos.

r->info = x;                       //substituir o valor do nó com 2 filhos.
return r;


}

//Função para verificar o tipo de nó que será removido.
AVLnode *remover_no(AVLnode *r) {
    //Verificar se o nó é uma folha (Não possui filhos).
    if (r->right == NULL && r->left == NULL) {
        //printf("O no %d eh uma folha.\n", r->n);
        r = remover_folha(r);
    }
    else {
        if (r->right == NULL) {
            //printf("O no %d possui 1 filho para esquerda.\n", r->n);
            r = remover_1filho_esquerda(r);
        }
        else {
            if (r->left == NULL) {
                //printf("O no %d possui 1 filho para direita.\n", r->n);
                r = remover_1filho_direita(r);
            }
            else {
                //printf("O no %d possui 2 filhos.\n", r->n);
                r = remover_2filhos(r);
            }
        }
    }
    return r;
}

AVLnode *remover_no_arvore(AVLnode *r, int x) {
    //Verificar se a árvore não está vazia.
    if (r != NULL) {
        //Se a árvore não está vazia, buscar o elemento x.
        if (r->info == x) {    //1 - Verificar se o elemento x está na raiz.
            //printf("ENCONTREI!: %d\n", r->n);
            r = remover_no(r);  //Chamar a função para remover o nó.
        }
        else {
            //Se x não está na raiz, verificar para qual lado x está.
            if (x < r->info) {
                //Fazer chamada recursiva para a esquerda.
                r->left = remover_no_arvore(r->left, x);
            }
            else {
                //Fazer chamada recursiva para a direita.
                r->right = remover_no_arvore(r->right, x);
            }
            r = verifica_balanceamento(r);
            //Verificar balanceamento da árvore.
        }
    }
    else {
        printf("Elemento nao encontrado: %d\n", x);
    }
    return r;
}

AVLnode *verifica_balanceamento(AVLnode *r) {
    int fb;
    fb = fatorBalanceamento_node(r);    //Após inserir o nó para esq ou dir, verificar Fator de bal.
    if (fb < -1) {
        if (fatorBalanceamento_node(r->left) > 0) {      //Rotação dupla a direita.
            Rdupla++; //conta rotações duplas.
            r->left = RotationLL(r->left);
        }
        r = RotationRR(r);             //Rotação simples a esquerda.
        rSimples++; //conta rotações simples.
    }
    else if (fb > 1) {
        if (fatorBalanceamento_node(r->right) < 0) {      //Rotação dupla a esquerda.
            Rdupla++; //conta rotações duplas.
            r->right = RotationRR(r->right);
        }
        r = RotationLL(r);            //Rotação simples a direita.
        rSimples ++; //conta rotações simples.
    }
    return r;
}