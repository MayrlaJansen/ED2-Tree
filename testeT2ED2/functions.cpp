#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"structs.h"
#include"AVL.h"
#include"Hash.h"
#include"RedBlack.h"
#include"binaria.h"
#include"lista.h"
#include"functions.h"
using namespace std;

vector<string> vector_of_words(string frase);
void ocurrences(Data* data, vector<string> doc);
AVLnode* AVLroot = NULL;
BinariaNode* Binariaroot = NULL;
// Hash* ha = createHash(1427);
Hash tab;
RBnode* RBroot= NULL;
sllist *l;
sllist *l2;


void AdicionarConjuntoB(){
    int info;
    l2 = sllCreate();
    char p;
    FILE *arquivo; 
    ifstream conjuntoA; 
    conjuntoA.open("menor.txt");
    vector<string> documento;
    while(!conjuntoA.eof()){
        char buffer[1000];
        conjuntoA.getline(buffer,1000);
        string str = buffer;
        documento.push_back(str);
    }
   arquivo = fopen ( "maior.txt", "r" );
    if (arquivo) {
        fscanf (arquivo, "%c" ,&p);
        // printf("%c",p);
        do {
            fscanf (arquivo, "%d" , &info);
            fscanf (arquivo, "%c" ,&p);
            // printf("%d", info);
            // if (info != '[' && info != ']' && info != ',' ) {
                Binariaroot = insert_BinariaNode (Binariaroot, info); //
                AVLroot = insert_AVLnode (AVLroot, info);
                RB_Insert (& RBroot, info);
                insereHash (tab, info);
                l2 = sllInsertLast (l2, info);
            // }
             } while (p != ']');
         }
         printf("L2\n");
          printar (l2);
    fclose (arquivo);
}

void AdicionarConjuntoA(){
    l = sllCreate();
    int info;
    char p;
    FILE *arquivo; 
    ifstream conjuntoA; 
    conjuntoA.open("menor.txt");
    vector<string> documento;
    while(!conjuntoA.eof()){
        char buffer[1000];
        conjuntoA.getline(buffer,1000);
        string str = buffer;
        documento.push_back(str);
    }
    arquivo = fopen("menor.txt","r"); 
    if (arquivo) {
        fscanf (arquivo, "%c" ,&p);
        // printf("%c",p);
        do{
            fscanf (arquivo, "%d" , &info);
            fscanf (arquivo, "%c" ,&p);
            // printf("%d", info);
            l = sllInsertLast(l, info); // INSERE O NUMERO NA LISTA
            }while(p != ']'); 
         }
         printf("L\n");
         printar(l);
    fclose(arquivo);

}

void menu(){
    int opcao;
    char text, path[100];
    bool fim = false;
    while (fim != true){
        cout<<"\t##########################################################"<<endl;
        cout<<"\t# Escolha a opção:                                       #"<<endl;
        cout<<"\t# 1) Buscar os elementos de A que estão em B.            #"<<endl;
        cout<<"\t# 2) Inserir em B, os elementos de A que não estão em B. #"<<endl;
        cout<<"\t# 3) Remover os elementos de A que estão em B.           #"<<endl;    
        cout<<"\t# 4) Sair.                                               #"<<endl;             
        cout<<"\t#########################################################"<<endl;
        cout<<endl;
        cout<<endl;
        cin>>opcao;
        switch (opcao){
            case 1: 
            buscarAemB();
            break;
            case 2:
            colocarAemB();
            printf("AQUI É A ARVORE BINARIA COM INSERCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            printarTree(Binariaroot);
            printf("AQUI É A AVL COM INSERCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            printarTree(AVLroot);
            printf("AQUI É A RB COM INSERCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            printarTree(RBroot); 
            printf("AQUI É O HASH COM INSERCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            imprimeHash(tab);
            printf("\nAQUI É A LISTA COM INSERCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            printar(l2);
            break;
            case 3:
            removerAemB();
            printf("AQUI É A ARVORE BINARIA COM REMOCAO DOS ELEMENTOS DE A QUE ESTAO EM B:\n");
            printarTree(Binariaroot);
            printf("AQUI É A AVL COM REMOCAO DOS ELEMENTOS DE A QUE ESTAO EM B:\n");
            printarTree(AVLroot);
            printf("AQUI É A RB COM REMOCAO DOS ELEMENTOS DE A QUE ESTAO EM B:\n");
            // printarTree(RBroot);
            printf("AQUI É O HASH COM REMOCAO DOS ELEMENTOS DE A QUE ESTAO EM B:\n");
            imprimeHash(tab);
            printf("\nAQUI É A LISTA COM REMOCAO DOS ELEMENTOS DE A QUE NAO ESTAO EM B:\n");
            printar(l2);
            break;
            case 4:
            cout<<"\t Fim de execução!"<<endl;
            // freeHash(ha);
            // Destroy(AVLroot);
            // Destroy(Binariaroot);
            // RBDestroy(RBroot);
            sllDestroy(l);
            fim = true;
            break;
            default:
            cout<<"\t Entrada inválida!"<<endl;
            cout<<"\t Pressione qualquer tecla pra retornar ao menu."<<endl;
            cin>>opcao;
            break;

        }
    }
    
}

void buscarAemB(){
    Sllnode *aux;
    int data;
    /*BINARIA*/
    if (l != NULL){
        if( l -> first != NULL){
            cout<<"Elementos encontrados na lista e na arvore binária:"<< endl;
            // cout<<"Arvore Binaria:"<<endl;
            // printarTree(Binariaroot);
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                BuscarnaBinaria(aux-> info);
                aux= aux->next;
            }
        }
    }
    cout<<"--"<< endl;
    /*AVL*/
    if (l != NULL){
        if( l -> first != NULL){
            cout<<"Elementos encontrados na lista e na AVL :"<< endl;
            // cout<<"Arvore Binaria:"<<endl;
            // printarTree(Binariaroot);
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                BuscarnaAVL(aux-> info);
                aux= aux->next;
            }
        }
    }
    cout<<"--"<< endl;
        /*RB*/
    if (l != NULL){
        if( l -> first != NULL){
            cout<<"Elementos encontrados na lista e na RB :"<< endl;
            // cout<<"Arvore Binaria:"<<endl;
            // printarTree(Binariaroot);
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                BuscarnaRB(aux-> info);
                aux= aux->next;
            }
        }
    }
    cout<<"--"<< endl;
    /*HASH*/
     if (l != NULL){
        if( l -> first != NULL){
            cout<<"Elementos encontrados na lista e no Hash :"<< endl;
            // cout<<"Arvore Binaria:"<<endl;
            // printarTree(Binariaroot);
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                BuscarnoHash(aux-> info);
                aux= aux->next;
            }
        }
    }
    cout<<"--"<< endl;
    /*LISTA*/
    if (l != NULL){
        if( l -> first != NULL){
            cout<<"Elementos encontrados na lista e na Lista2 :"<< endl;
            // cout<<"Arvore Binaria:"<<endl;
            // printarTree(Binariaroot);
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                BuscarnaLista(aux-> info);
                aux= aux->next;
            }
        }
    }
    cout<<"--"<< endl;
}
void BuscarnaBinaria(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = QueryB(Binariaroot, busca, &passos);
    if (stat != 0){
        cout<<busca<< endl;
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void BuscarnaAVL(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = Query(AVLroot, busca, &passos);
    if (stat != 0){
        cout<<busca<< endl;
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
}

void BuscarnaRB(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = Query(RBroot, busca, &passos);
    if (stat != 0){
        cout<<busca<< endl;
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void BuscarnoHash(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = buscaHash(tab, busca, &passos);
    // if (stat != -1){
    //     cout<<busca<< endl;
    // }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void BuscarnaLista(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = sllQuerry(l2, busca, &passos);
    if (stat != -1){
        cout<<busca<< endl;
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}

void printar(sllist *l){
    Sllnode *aux;
    if(l != NULL){
        if(l->first != NULL){
            aux = l->first;
            // int value = ( (int)aux->data);
            cout<<aux->info<< endl;
            while(aux->next != NULL){
                aux = aux->next;
                int value = ((unsigned int)aux->info);
                cout<<value<< endl;
            }
        }else{
            printf("A lista está vazia ! \n\n\n");
        }
    }else{
        printf("ERRO ! LISTA NÃO ALOCADA !!! \n\n\n");
    }
}

void colocarAemB(){
    Sllnode *aux;
    int data;
    /*BINARIA*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                ColocarnaBinaria(aux-> info);
                aux= aux->next;
            }
        }
    }
    /*AVL*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                ColocarnaAVL(aux-> info);
                aux= aux->next;
            }
        }
    }
    //     /*RB*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                ColocarnaRB(aux-> info);
                aux= aux->next;
            }
        }
    }
    /*HASH*/
     if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar no Hash*/
                ColocarnoHash(aux-> info);
                aux= aux->next;
            }
        }
    }
    /*LISTA*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Lista*/
                ColocarnaLista(aux-> info);
                aux= aux->next;
            }
        }
    }
}
void ColocarnaBinaria(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = QueryB(Binariaroot, busca, &passos);
    if (stat == 0){
        Binariaroot = insert_BinariaNode(Binariaroot, busca); 
    }
    // cout<<"tempo gasto para colocar na Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void ColocarnaAVL(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = Query(AVLroot, busca, &passos);
    if (stat == 0){
        AVLroot = insert_AVLnode(AVLroot, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
}

void ColocarnaRB(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = Query(RBroot, busca, &passos);
    if (stat == 0){
        RB_Insert(&RBroot, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void ColocarnoHash(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = buscaColocaHash(tab, busca, &passos);
    cout<<stat<< endl;
    if (stat == 0){
        insereHash(tab,busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void ColocarnaLista(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = sllQuerry(l2, busca, &passos);
    if (stat == -1){
        l2 = sllInsertLast(l2, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void removerAemB(){
    Sllnode *aux;
    int data;
    /*BINARIA*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                RemovernaBinaria(aux-> info);
                aux= aux->next;
            }
        }
    }
    /*AVL*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Binaria*/
                RemovernaAVL(aux-> info);
                aux= aux->next;
            }
        }
    }
    // //     /*RB*/
    // if (l != NULL){
    //     if( l -> first != NULL){
    //         aux = l-> first;
    //         while(aux != NULL){
    //             /*buscar na Binaria*/
    //             RemovernaRB(aux-> info);
    //             aux= aux->next;
    //         }
    //     }
    // }
    // /*HASH*/
     if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar no Hash*/
                RemovernoHash(aux-> info);
                aux= aux->next;
            }
        }
    }
    // /*LISTA*/
    if (l != NULL){
        if( l -> first != NULL){
            aux = l-> first;
            while(aux != NULL){
                /*buscar na Lista*/
                RemovernaLista(aux-> info);
                aux= aux->next;
            }
        }
    }
}
void RemovernaBinaria(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = QueryB(Binariaroot, busca, &passos);
    // printf("stat %d",stat);
    if (stat == 1){
        removeB(Binariaroot,busca);
    }
    // cout<<"tempo gasto para Remover na Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void RemovernaAVL(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    stat = Query(AVLroot, busca, &passos);
    // printf("stat %d",stat);
    if (stat != 0){
        AVLroot = remover_no_arvore(AVLroot, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
}

void RemovernaRB(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = Query(RBroot, busca, &passos);
    if (stat == 0){
        RB_Insert(&RBroot, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void RemovernoHash(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = buscaColocaHash(tab, busca, &passos);
    cout<<stat<< endl;
    if (stat != 0){
        removeHash(tab,busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}
void RemovernaLista(int data){
    int passos = 0;
    int stat;
    int busca = data;
    
    
    stat = sllQuerry(l2, busca, &passos);
    if (stat != -1){
        sllRemoveSpec(l2, busca);
    }
    // cout<<"tempo gasto na busca Binaria: "<<passos<<" passos para o dado "<<data<<endl;
    
}