#include <iostream>
#include <vector>
#include <chrono>
#include "buscas.hpp"

int main (){
    const int tamanho_inicial = 0; //tamanho inicial do vetor
    const int tamanho_final = 500000; //tamanho final do vetor
    const int passo = 5000; // para gerar +100 pontos no gráfico  
    const int repeticoes = 10; // número de repetições para cada tamanho do vetor

    cout << "Tamanho,Tempo_NS\n";

    for (int tamanho = tamanho_inicial; tamanho <= tamanho_final; tamanho += passo) {
        vector<int> vet(tamanho);
        for (int i = 0; i < tamanho; ++i) {
            vet[i] = i; // Preenche o vetor com valores de 0 a tamanho-1
        }

        int alvo = -1; // valor que não está presente no vetor para testar o pior caso
        long long tempo_total = 0;

        for (int rep = 0; rep < repeticoes; ++rep) {
            auto inicio = chrono::high_resolution_clock::now();
            volatile bool encontrado = buscaSequencialAltRecursiva(vet, 0, vet.size(), alvo);
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        long long tempo_medio = tempo_total / repeticoes;
        cout << tamanho << "," << tempo_medio << "\n";
    }

    return 0;
}