#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

#include <bits/stdc++.h>

using namespace std;

// 1. Remover pontuação e passar tudo para minúsculo
string cleanWord(const string& word);

// 2. Função sequencial para ler o arquivo e contar palavras
void processFile(const string &filename, unordered_map<string, int> &wordCount);

// 3. Função para gerar o histograma
void printHistogram(const unordered_map<string, int>& wordCount, int topN = 15);

#endif // SEQUENCIAL_H