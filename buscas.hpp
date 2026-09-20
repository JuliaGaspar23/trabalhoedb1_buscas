#include <vector>
using namespace std;

//Busca Linear Iterativa 
bool buscaLinearIterativa(const vector<int>& vec, int esq, int dir, int target){ //percorre o vetor da esquerda para a direita 
    for (int i = esq; i < dir; ++i){
        if (vec[i] == target){ //target é o alvo que eu quero encontrar
            return true; // se encontrar o alvo, retorna true
        }
    }
    return false; // se não encontrar o alvo, retorna false
}

//Busca Linear Recursiva
bool buscaLinearRecursiva(const vector<int>& vec, int esq, int dir, int target){
    if (esq >= dir){ // se o índice da esquerda for maior ou igual ao índice da direita, significa que não encontrou o alvo
        return false; 
    }
    if (vec[esq] == target){ // se o elemento na esquerda for igual ao alvo, significa que encontrou o alvo
        return true; 
    }
    return buscaLinearRecursiva(vec, esq + 1, dir, target); // chama a função novamente, incrementando o índice da esquerda
}

//Busca Sequencial Alternativa - Versão Iterativa
bool buscaSequencialAltIterativa(vector<int>& vec, int esq, int dir, int target){
    if (esq >= dir)
     return false;
    int ultimoValorOriginal = vec[dir - 1]; // guarda o último valor original do vetor
    vec[dir - 1] = target;// substitui o último valor do vetor pelo alvo
    int i = esq;
    while (vec[i] != target) { // enquanto o elemento na posição i for diferente do alvo, continua percorrendo o vetor
        i++;
    }
    vec[dir - 1] = ultimoValorOriginal;
    return i < dir;
}

//Busca Sequencial Alternativa - Versão Recursiva
bool buscaSequencialAltRecursiva(vector<int>& vec, int esq, int dir, int target){
    if (esq >= dir)
        return false;
    int ultimoValorOriginal = vec[dir - 1]; // guarda o último valor original do vetor
    vec[dir - 1] = target; // substitui o último valor do vetor pelo alvo
    if (vec[esq] == target) { // se o elemento na esquerda for igual ao alvo, significa que encontrou o alvo
        vec[dir - 1] = ultimoValorOriginal; // restaura o último valor original do vetor
        return true;
    }
    bool resultado = buscaSequencialAltRecursiva(vec, esq + 1, dir, target);
    vec[dir - 1] = ultimoValorOriginal;
    return resultado;
}
//Busca Binária Iterativa
//precisa estar ordenado  
bool buscaBinariaIterativa(const vector<int>& vec, int esq, int dir, int target){
    while (esq < dir) {
        int meio = esq + (dir - esq) / 2; // calcula o índice do meio
        if (vec[meio] == target) { // se o elemento no meio for igual ao alvo, significa que encontrou o alvo
            return true;
        }
        else if (vec[meio] < target) { // se o elemento no meio for menor que o alvo, significa que o alvo está na metade direita
            esq = meio + 1; // atualiza o índice da esquerda para a metade direita
        }
        else { // se o elemento no meio for maior que o alvo, significa que o alvo está na metade esquerda
            dir = meio; // atualiza o índice da direita para a metade esquerda
        }
    }
    return false; // se não encontrar o alvo, retorna false
}

//Busca Binária Recursiva
bool buscaBinariaRecursiva(const vector<int>& vec, int esq, int dir, int target){
    if (esq >= dir) { // se o índice da esquerda for maior ou igual ao índice da direita, significa que não encontrou o alvo
        return false;
    }
    int meio = esq + (dir - esq) / 2; // calcula o índice do meio
    if (vec[meio] == target) { // se o elemento no meio for igual ao alvo, significa que encontrou o alvo
        return true;
    }
    else if (vec[meio] < target) { // se o elemento no meio for menor que o alvo, significa que o alvo está na metade direita
        return buscaBinariaRecursiva(vec, meio + 1, dir, target); // chama a função novamente, atualizando o índice da esquerda para a metade direita
    }
    else { // se o elemento no meio for maior que o alvo, significa que o alvo está na metade esquerda
        return buscaBinariaRecursiva(vec, esq, meio, target); // chama a função novamente, atualizando o índice da direita para a metade esquerda
    }
}

//Busca Ternária Iterativa
bool buscaTernariaIterativa(const vector<int>& vec, int esq, int dir, int target){
    while (esq < dir) {
        int m1 = esq + (dir - esq) / 3; // calcula o primeiro índice do meio
        int m2 = dir - (dir - esq) / 3; // calcula o segundo índice do meio
        if (vec[m1] == target) { // se o elemento no primeiro meio for igual ao alvo, significa que encontrou o alvo
            return true;
        }
        if (vec[m2] == target) { // se o elemento no segundo meio for igual ao alvo, significa que encontrou o alvo
            return true;
        }
        if (target < vec[m1]) { // se o alvo for menor que o elemento no primeiro meio, significa que o alvo está na primeira parte
            dir = m1; // atualiza o índice da direita para a primeira parte
        }
        else if (target > vec[m2]) { // se o alvo for maior que o elemento no segundo meio, significa que o alvo está na terceira parte
            esq = m2 + 1; // atualiza o índice da esquerda para a terceira parte
        }
        else { // se o alvo estiver entre os dois meios, significa que está na segunda parte
            esq = m1 + 1; // atualiza o índice da esquerda para a segunda parte
            dir = m2; // atualiza o índice da direita para a segunda parte
        }
    }
    return false; // se não encontrar o alvo, retorna false
}

//Busca Ternária Recursiva
bool buscaTernariaRecursiva(const vector<int>& vec, int esq, int dir, int target){
    if (esq >= dir) { // se o índice da esquerda for maior ou igual ao índice da direita, significa que não encontrou o alvo
        return false;
    }
    int m1 = esq + (dir - esq) / 3; // calcula o primeiro índice do meio
    int m2 = dir - (dir - esq) / 3; // calcula o segundo índice do meio
    if (vec[m1] == target) { // se o elemento no primeiro meio for igual ao alvo, significa que encontrou o alvo
        return true;
    }
    if (vec[m2] == target) { // se o elemento no segundo meio for igual ao alvo, significa que encontrou o alvo
        return true;
    }
    if (target < vec[m1]) { // se o alvo for menor que o elemento no primeiro meio, significa que o alvo está na primeira parte
        return buscaTernariaRecursiva(vec, esq, m1, target); // chama a função novamente, atualizando os índices para a primeira parte
    }
    else if (target > vec[m2]) { // se o alvo for maior que o elemento no segundo meio, significa que o alvo está na terceira parte
        return buscaTernariaRecursiva(vec, m2 + 1, dir, target); // chama a função novamente, atualizando os índices para a terceira parte
    }
    else { // se o alvo estiver entre os dois meios, significa que está na segunda parte
        return buscaTernariaRecursiva(vec, m1 + 1, m2, target); // chama a função novamente, atualizando os índices para a segunda parte
    }
}

