#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Grafo.h"

using namespace std;

void lerArquivoGrafo(const string& caminhoArquivo, Grafo& grafo, bool ponderado) {
    ifstream arquivo(caminhoArquivo);
    string linha, origem, destino;
    int peso;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << endl;
        return;
    }

    while (std::getline(arquivo, linha)) {
        istringstream iss(linha);
        getline(iss, origem, ';');
        getline(iss, destino, ';');
        if (ponderado) {
            iss >> peso;
        } else {
            peso = 0;
        }
        grafo.adicionarAresta(origem, destino, peso);
    }

    arquivo.close();
}

int main() {
    Grafo g1(false);
    Grafo g2(true);
    Grafo g3(false);

    lerArquivoGrafo("grafos/g1.txt", g1, false);
    lerArquivoGrafo("grafos/g2.txt", g2, false);
    lerArquivoGrafo("grafos/g3.txt", g3, true);

    g1.ordenarVertices();
    g2.ordenarVertices();

    cout << "LISTAS DE ADJACÊNCIA DE CADA GRAFO" << endl;
    cout << "Grafo g1:" << endl;
    g1.imprimirListaAdjacencia();
    cout << endl;

    cout << "\nGrafo g2:" << endl;
    g2.imprimirListaAdjacencia();
    cout << endl;

    cout << "\nGrafo g3:" << endl;
    g3.imprimirListaAdjacencia();
    cout << endl;

    
    cout << "BUSCA EM LARGURA" << endl;
    cout << "Busca em Largura para G1 a partir do vértice 'b':" << endl;
    g1.buscaEmLargura("b");
    cout << endl;

    cout << "\nBUSCA EM PROFUNDIDADE" << endl;
    cout << "Busca em Profundidade para G2 a partir do vértice 'a':" << endl;
    g2.buscaEmProfundidade("a");
    cout << endl;

    return 0;
}