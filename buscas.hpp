#include <vector>
using namespace std;

//Busca Linear Iterativa 
bool buscaLinearIterativa(const vector<int>& vec, int esq, int dir, int target){
    for (int i = esq; i < dir; ++i){
        if (vec[i] == target){
            return true;
        }
    }
    return false;
}

//Busca Linear Recursiva

//Busca Sequencial Alternativa - Versão Iterativa

//Busca Sequencial Alternativa - Versão Recursiva

//Busca Binária Iterativa

//Busca Binária Recursiva

//Busca Ternária Iterativa

//Busca Ternária Recursiva

