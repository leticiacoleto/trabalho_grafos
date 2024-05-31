//inclusão bibliotecas
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Grafo.h"

using namespace std;

void lerArquivoGrafo(const string& caminhoArquivo, Grafo& grafo, bool ponderado) {
    //abre o arquivo para leitura
    ifstream arquivo(caminhoArquivo);
    string linha, origem, destino;
    int peso;

    //verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << endl;
        return;
    }

    //faz a leitura do arquivo linha a linha
    while (getline(arquivo, linha)) {
         //divide a linha em substrings usando ';' como delimitador
        istringstream iss(linha);
        getline(iss, origem, ';');
        getline(iss, destino, ';');

        if (ponderado) {//se o grafo for ponderado, isto é, possui peso, lê o peso da aresta
            iss >> peso;
        } else {
            peso = 0;
        }

        grafo.adicionarAresta(origem, destino, peso);  //adiciona a aresta ao grafo
    }

    arquivo.close();
}

int main() {
    //criação dos três Grafos
    Grafo g1(false); //grafo não orientado
    Grafo g2(true);  //grado orientado 
    Grafo g3(false); //grafo não orientado

    //chamada da função para ler arquivos dos grafos, passando se ele possui peso ou não
    lerArquivoGrafo("grafos/g1.txt", g1, false);
    lerArquivoGrafo("grafos/g2.txt", g2, false);
    lerArquivoGrafo("grafos/g3.txt", g3, true);

    //impressão das listas de adjacência dos três grafos
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

    //impressão da busca por largura e por profundidade
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