#include "Hash.h"
#include<stdio.h>
#include<stdlib.h>
// #include<windows.h>
#include<time.h>
// #include<conio.h>

// int chaveMultiplicacao(int chave, int TABLE_SIZE){
//     float A = 0.618;
//     float val = chave*A;
//     val = val - (int)val;
//     return (int)(TABLE_SIZE*val);
// }

// int chaveDivisao(int chave, int TABLE_SIZE){
//     return (chave & 0x7FFFFFFF)% TABLE_SIZE;
// }

// int chaveDobra(int chave,int TABLE_SIZE){
//     int num_bits=10;
//     int parte1 = chave >> num_bits;
//     int parte2 = chave & (TABLE_SIZE-1);
//     return (parte1^parte2);
// }

// int valorString(string str){
//     int valor = 0;
//     int tam = str.size();
//     for(int i=0; i< tam; i++){
//         valor = 31*valor + static_cast<int>(str[i]);
//     }
//     return valor;
// }

// int sondagemLinear(int pos, int i, int TABLE_SIZE){
//     return ((pos+i) & 0x7FFFFFF) % TABLE_SIZE;
// }

// int sondagemQuadratica(int pos, int i,int TABLE_SIZE){
//     pos = pos + 2*i + 5*i*i;
//     return (pos & 0x7FFFFFFF) % TABLE_SIZE;
// }

// Hash* createHash(int TABLE_SIZE){
//     Hash* ha = (Hash*)malloc(sizeof(Hash));

//     if(ha != NULL){
//         int i;
//         ha->TABLE_SIZE = TABLE_SIZE;
//         ha->itens = (Data**)malloc(TABLE_SIZE*sizeof(Data*));
//         if(ha->itens == NULL){
//             free(ha);
//             return NULL;
//         }
//         ha->qtd = 0;
//         for(i = 0; i < ha->TABLE_SIZE; i++)
//             ha->itens[i] = NULL;

//         return ha;
//     }

//     return NULL;
// }

// void freeHash(Hash* ha){
//     if(ha != NULL){
//         int i;
//         for(i = 0; i < ha->TABLE_SIZE; i++){
//             if(ha->itens[i] != NULL)
//                 free(ha->itens[i]);
//         }
//         free(ha->itens);
//         free(ha);
//     }
// }

// // int insereHash_EnderAberto(Hash* ha, Data* dado){
// //     if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
// //         return 0;
// //     int chave = dado->key;
// //     int i, pos, newPos;
// //     pos = chaveDivisao(chave, ha->TABLE_SIZE);
// //     for(i=0; i<ha->TABLE_SIZE; i++){
// //         newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
// //         if(ha->itens[newPos] == NULL){
// //             Data* novo;
// //             novo = (Data*)malloc(sizeof(Data));
// //             if(novo == NULL)
// //                 return 0;
// //             novo = dado;
// //             ha->itens[newPos] = novo;
// //             ha->qtd++;
// //             return 1;
// //         }
// //     }
// //     return 0;
// // }


// int buscaHash_EnderAberto(Hash* ha, int key, Data** dado,int* passos){
//     if(ha == NULL)
//         return 0;
//     int i, pos, newPos;
//     pos = chaveDivisao(key, ha->TABLE_SIZE);
//     for(i=0; i<ha->TABLE_SIZE; i++){
//         newPos = sondagemQuadratica(pos, i, ha->TABLE_SIZE);
//         *passos = *passos+1;
//         if(ha->itens[newPos] == NULL)
//             return 0;
//         if(ha->itens[newPos]->key == key){
//             *dado = ha->itens[newPos];
//             return 1;
//         }
//     }
//     return 0;
// }

int funcaoHash(int num)
{
  return(num%tam);
}
void inicializaHash(Hash tab)
{
 int i;
 for(i = 0; i < tam; i++)
 {
  tab[i] = NULL;
 }
}

void insereHash(Hash tab, int num)
{
 int i = 0;
 int chave = funcaoHash(num);
 Dados* aux = tab[chave];
 while(aux != NULL)
 {
  if(aux->info == num)
  {
   break;
  }
  aux = aux->prox;
 }
 if(aux == NULL)
 {
  aux = (Dados*)malloc(sizeof(Dados));
  aux->info = num;
  aux->prox = tab[chave];
  tab[chave] = aux;
 }
}

int buscaHash(Hash tab,int num, int* passos)
{
 int pos = num;
 if(num > tam || num < 0)
 {
  printf("\nPosicao nao encontrada!");
  return 0;
 }else{
     
  imprimeColisao(tab,pos);
    *passos = *passos + 1;
    // return num;
    }
}

void imprimeHash(Hash tab)
{
 int  i = 0,cont = 0;
 for(i = 0; i < tam; i++)
 {
  if(tab[i] != NULL)
  {
   printf("\n %d",tab[i]->info);
   Dados* aux =tab[i]->prox;
   while(aux!=NULL)
   {
    printf(" -> %3d",aux->info);
     aux=aux->prox;
   }
  }
 }
}

void removeHash(Hash tab, int num)
{
 int pos = num;
 int ex ;
 if(num > tam)
 {
  printf("\nEsta posicao nao existe na tabela!");
 }else{
  if(tab[pos] == NULL)
  {
   printf("Esta chave esta vazia!");
  }else
  {
   printf("\n\n\n");
   imprimeColisao(tab,pos);
   printf("\n\nQual registro deseja apagar =  ");
   scanf("%d",&ex);
   if(tab[pos]->info == ex)
   {
    if(tab[pos]->prox == NULL)
    {
     tab[pos] = NULL;
     return;
    }
    if(tab[pos]->prox != NULL)
    {
     tab[pos]->info = tab[pos]->prox->info;
     tab[pos]->prox = tab[pos]->prox->prox;
     return;
    }
   }else{
   if(tab[pos]->info != ex)
   {

    if(tab[pos]->prox == NULL)
    {
     printf("\nRegistro nao encontrado!");

    //  getch();
     return;
    }else{
    Dados* ant = NULL;
    Dados* aux = tab[pos]->prox;
    while(aux->prox != NULL  && aux->info != ex)
    {
     ant = aux;
     aux = aux->prox;
    }
    if(aux->info != ex)
    {
     printf("\nRegistro nao encontrado!\n");
     return;
    }else
    {
    if(ant == NULL)
    {
     tab[pos]->prox = aux->prox;
    }else{
         ant->prox = aux->prox;
        }
        aux = NULL;
        free(aux);
        }
      }
     }
    }
   }
  }
}

int imprimeColisao(Hash tab, int pos)
{
 Dados* aux = tab[pos];
 if(aux == NULL)
 {
//   printf("Esta posicao esta vazia!");
  return 0;
 }else
 {
  if(aux != NULL)
  {
   printf("%3d",aux->info);
   while(aux->prox != NULL)
   {
    printf(" -> %d",aux->prox->info);
    aux = aux->prox;
    return 0;
   }
  }
 }
}
