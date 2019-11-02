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

// vector<string> vector_of_words(string frase);
// void ocurrences(Data* data, vector<string> doc);

int main(){
    AVLnode* AVLroot = NULL;
    // BinariaNode* Binariaroot = NULL;
    // Hash* ha = inicializaHash(1427);
    Hash tab;
    RBnode* RBroot= NULL;

    /*adicionando o menor arquivo a uma lista encadeada*/
    AdicionarConjuntoA();

    // /*adicionando o maior arquivo a uma AVL, RB, BINARIA E HASH*/
    AdicionarConjuntoB();
    // // printf("treeB");
    // // // printarTree(Binariaroot);
    menu();


    

    
    return 0;
}

//Pega palavras da frase
vector<string> vector_of_words(string frase){
    vector<string> vet;
    string del = " ";//delimitador
    size_t pos = 0;
    string word;
    while((pos = frase.find(del)) != string::npos){
        word = frase.substr(0, pos);
        vet.push_back(word);
        frase.erase(0, pos + del.length());
    }
    //Para pegar a �ltima palavra da frase
    word = frase.substr(0, pos);
    vet.push_back(word);

    return vet;
}

/*Fun��o que verifica as ocorr�ncias no texto
  e preencher o struct data*/
void ocurrences(Data* data, vector<string> doc){
    //ver onde ocorre a palavra
    int line = 1;
    for(int i = 0; i < doc.size(); i++){
        if(doc[i].find(data->palavra) != string::npos){
            data->linhas.push_back(doc[i]);
            data->ocorrencias.push_back(line);
        }
        line++;
    }
}
