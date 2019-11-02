#ifndef _LISTA_H_
#define _LISTA_H_
#include "structs.h"
#define TRUE 1
#define FALSE 0

typedef struct _sllnode_{
  struct _sllnode_ *next;
  int info;
}Sllnode;

// estrutura da lista
typedef struct _sllist_{
  Sllnode *first, *cur;

}sllist;

sllist *sllCreate();
sllist *sllInsertLast(sllist *l, int inf);
int sllQuerry(sllist *l, int key, int* passos);
int sllRemoveSpec(sllist *l,int key);
int sllDestroy(sllist *l);

#endif