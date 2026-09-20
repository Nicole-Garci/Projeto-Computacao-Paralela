#include <bits/stdc++.h>
#include "sequencial.h"

using namespace std;

// 1. Remover pontuação e passar tudo para minúsculo
string cleanWord(string& word){
    string cleaned;
    for (size_t i = 0; i < word.size();) {
        if (i == 0 && word.size() >= 3 &&
            static_cast<unsigned char>(word[0]) == 0xEF &&
            static_cast<unsigned char>(word[1]) == 0xBB &&
            static_cast<unsigned char>(word[2]) == 0xBF) {
            i = 3;
            continue;
        }

        unsigned char c = static_cast<unsigned char>(word[i]);
        if (c < 128) {
            if (isalnum(c)) {
                cleaned += static_cast<char>(tolower(c));
            }
            ++i;
            continue;
        }

        size_t length = (c & 0xE0) == 0xC0 ? 2 :
                        (c & 0xF0) == 0xE0 ? 3 :
                        (c & 0xF8) == 0xF0 ? 4 : 1;
        if (i + length <= word.size()) {
            string character = word.substr(i, length);
            static unordered_map<string, string> uppercaseToLowercase = {
                {"À", "à"}, {"Á", "á"}, {"Â", "â"}, {"Ã", "ã"}, {"Ä", "ä"},
                {"Ç", "ç"}, {"È", "è"}, {"É", "é"}, {"Ê", "ê"}, {"Ë", "ë"},
                {"Ì", "ì"}, {"Í", "í"}, {"Î", "î"}, {"Ï", "ï"}, {"Ò", "ò"},
                {"Ó", "ó"}, {"Ô", "ô"}, {"Õ", "õ"}, {"Ö", "ö"}, {"Ù", "ù"},
                {"Ú", "ú"}, {"Û", "û"}, {"Ü", "ü"}, {"Ç", "ç"}
            };
            auto lowercase = uppercaseToLowercase.find(character);
            cleaned += lowercase == uppercaseToLowercase.end() ? character : lowercase->second;
        }
        i += length;
    }
    return cleaned;
}

// 2. Função sequencial para ler o arquivo e contar palavras
void processFile(string &filename, unordered_map<string, int> &wordCount){
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
void printHistogram(unordered_map<string, int>& wordCount, int topN){
    // Criar um vetor de pares (palavra, contagem) e ordená-lo por contagem
    vector<pair<string, int>> sortedWords(wordCount.begin(), wordCount.end());
    sort(sortedWords.begin(), sortedWords.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return b.second < a.second; // Ordenar em ordem decrescente
    });

    // Imprimir as N palavras mais frequentes
    cout << "Palavras mais frequentes:\n";
    for (int i = 0; i < min(topN, (int)sortedWords.size()); ++i) {
        cout << sortedWords[i].first << ": " << sortedWords[i].second << "\n";
    }
}