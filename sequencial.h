#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

#include <bits/stdc++.h>

using namespace std;

// 1. Remover pontuação e passar tudo para minúsculo
string cleanWord(string& word);

// 2. Função sequencial para ler o arquivo e contar palavras
void processFile(string &filename, unordered_map<string, int> &wordCount);

// 3. Função para gerar o histograma
void printHistogram(unordered_map<string, int>& wordCount, int topN);

#endif // SEQUENCIAL_H