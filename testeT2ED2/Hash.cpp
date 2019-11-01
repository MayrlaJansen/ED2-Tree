#include "Hash.h"
#include<stdio.h>
#include<stdlib.h>
// #include<windows.h>
#include<time.h>
// #include<conio.h>


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

int buscaColocaHash(Hash tab,int num, int* passos)
{
 int pos = num;
 if(num > tam || num < 0)
 {
  printf("\nPosicao nao encontrada!");
  return 0;
 }else{
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
     return 0;
    }
    return 1;
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
    return num;
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
