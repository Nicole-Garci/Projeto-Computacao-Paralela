#include <bits/stdc++.h>
#include "sequencial.h"
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
using namespace std::chrono;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // Lista de arquivos a serem processados
    vector<string> files = {"arquivo1.txt", "arquivo2.txt", "arquivo3.txt", "PequenaSereia.txt", "Odisseia.txt", "./generated_words/100MB.txt", "./generated_words/1000MB.txt"};
    
    // TESTE DA IMPLEMENTAÇÃO SEQUENCIAL
    cout << "=== INICIANDO PROCESSAMENTO SEQUENCIAL ===\n";
    for(auto &file : files) {
        unordered_map<string, int> wordCount;
        auto start = high_resolution_clock::now();
        processFile(file, wordCount);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Tempo de processamento para " << file << ": " << duration.count()*1e-9 << " s = " << duration.count() << " ns\n";

        cout << "Histograma para o arquivo: " << file << "\n";
        printHistogram(wordCount, 15);
    }

    return 0;
}