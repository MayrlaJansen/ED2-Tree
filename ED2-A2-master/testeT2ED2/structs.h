#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include <string>
#include<vector>
using namespace std;

int valorString(string str);

typedef struct _data_{
   int key;
   string palavra;
   vector<string> linhas;
   vector<int> ocorrencias;
} Data;
#endif






