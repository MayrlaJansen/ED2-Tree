#include"lista.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

	
sllist *sllCreate(){
  sllist *l;
  l=(sllist*)malloc(sizeof(sllist));
  if (l != NULL){
    l->first = l->cur = NULL;
    return l;
  }
  return NULL;
}


//inserindo ultimo
sllist * sllInsertLast(sllist *l, int data){
  Sllnode *newnode;
  Sllnode *last;
  if ( l!= NULL){
    newnode= new Sllnode;
    if(newnode != NULL){
      newnode->info = data;
      newnode-> next = NULL; 
      if(l-> first == NULL){
        l->first = newnode;
      }else{
        last = l->first;
        while(last->next != NULL){
          last = last->next; //pulando para o proximo
        }
        last->next = newnode;
      }
      return l;
    }
  }
  return FALSE;
}



//busca
// int sllQuery(sllist *l,void * key, *int passos){
//   Sllnode *cur;
//   int stat;
//   if( l!= NULL){
//     if(l->first != NULL){
//       cur = l->first;
//       stat=cmp(key,cur->info);
//       while(stat!= TRUE && cur->next != NULL){
//         cur = cur->next;
//         stat=cmp(key,cur->info);
//       }
//       if(stat == TRUE){
//         return cur->info;
//       }
//     }
//   }
//   return NULL;
// }
int sllQuerry(sllist *l, int key, int* passos){
  Sllnode * cur;
  if (l != NULL){
    if(l ->first != NULL){
      cur = l -> first;
      while ( cur != NULL){
        if (cur->info == key){
          *passos = *passos + 1;
          return 0;
        }
        cur = cur->next;
      }
      *passos = *passos + 1;
      return -1;
    }
  }
    return -1;
  

}


//remover o spec
// int sllRemoveSpec(sllist *l,int key){
//   Sllnode *spec,*prev;
//   int stat;
//   int data;
//   if(l != NULL){
//     if (l->first != NULL){
//       prev = NULL;
//       spec=l->first;
//       stat=cmp(key,spec->info);
//       while(stat != TRUE && spec->next != NULL){
//         prev = spec;
//         spec= spec->next;
//         stat = cmp(key,spec->info);
//       }
//       if(stat == TRUE){
//         if(prev == NULL){
//           l->first=spec->next;
//         }else{
//           prev->next= spec->next;
//         }
//         data=spec->info;
//         free(spec);
//         return data;
//       }
//     }
//   }
//   return 0;
// }

// int sllRemoveSpec(sllist *l,int key){
//   Sllnode *spec,*prev;
//   int stat;
//   int data;
//   if(l != NULL){
//     if (l->first != NULL){
//       prev = NULL;
//       spec=l->first;
//       // stat=cmp(key,spec->info);
//       while(stat != TRUE && spec->next != NULL){
//         if (key == spec -> info){
//           stat == TRUE;
//         }
//         prev = spec;
//         spec= spec->next;
//       }
//       if(stat == TRUE){
//         if(prev == NULL){
//           l->first=spec->next;
//         }else{
//           prev->next= spec->next;
//         }
//         data=spec->info;
//         free(spec);
//         return data;
//       }
//     }
//   }
//   return 0;
// }

int sllRemoveSpec(sllist *l,int key){
  Sllnode *spec,*prev;
  int stat = FALSE;
  int data;
  
  if (l != NULL){
    if (l->first != NULL){
      prev = NULL;
      spec = l ->first;
      if (spec->info == key){
          stat = TRUE;
      }
      while (stat !=TRUE && spec->next != NULL){
        prev = spec;
        spec= spec->next;
        if (spec->info == key){
          stat = TRUE;
        }
        
      }
      if(stat == TRUE){
        if(prev == NULL){
          l->first=spec->next;
        }else{
          prev->next= spec->next;
        }
        data=spec->info;
        free(spec);
        return data;
      }
      return 0;
    }
    return 0;
  }
  return 0;
}
//destruir a lista
int sllDestroy(sllist *l){
  if (l!= NULL){
    if(l->first == NULL){
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

