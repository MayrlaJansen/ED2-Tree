#ifndef _HASH_H_
#define _HASH_H_
#include <stdlib.h>
#include <string.h>
#include "structs.h"
// typedef struct _hash_{
//    int qtd, TABLE_SIZE;
//    Data **itens;
// } Hash;

// Hash* createHash(int TABLE_SIZE);
// void freeHash(Hash* ha);
// int buscaHash_EnderAberto(Hash* ha, int key, Data** dado,int* passos);
// int insereHash_EnderAberto(Hash* ha, Data* dado);

#define tam 677

/*hash.h armazena a estrutura e os prototipos das funcaoes*/
struct dados
{
  int info;
  struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];


int funcaoHash(int num);/**/
void inicializaHash(Hash tab); /**/
void insereHash(Hash tab,int num);
int buscaHash(Hash tab, int num, int* passos);
void imprimeHash(Hash tab);
void removeHash(Hash tab, int num);
int imprimeColisao(Hash tab, int pos);

#endif
