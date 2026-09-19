#include <bits/stdc++.h>
#include <sequencial.h>

using namespace std;

// 1. Remover pontuação e passar tudo para minúsculo
string cleanWord(const string& word){
    string cleaned;
    for (char c : word) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// 2. Função sequencial para ler o arquivo e contar palavras
void processFile(const string &filename, unordered_map<string, int> &wordCount){
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
void printHistogram(const unordered_map<string, int>& wordCount, int topN = 15){
}