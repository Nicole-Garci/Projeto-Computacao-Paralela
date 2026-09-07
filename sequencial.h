#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

#include <bits/stdc++.h>

using namespace std;

// O 'inline' é para evitar erros de múltipla definição

// 1. Função para limpar a palavra (remover pontuação e passar tudo para UPCASE)
inline string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c)) { // Mantém apenas letras e números
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// 2. Função sequencial para ler o arquivo e contar palavras
inline void processFile(const string &filename, unordered_map<string, int> &wordCount) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << "\n";
        return;
    }

    string word;
    // Lê o arquivo palavra por palavra (separado por espaços)
    while (file >> word) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            wordCount[cleaned]++;
        }
    }
    
    file.close();
}

// 3. Função para gerar o histograma
inline void printHistogram(const unordered_map<string, int>& wordCount, int topN = 15) {
}

#endif // SEQUENCIAL_H