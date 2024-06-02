//Fernanda Bonfim Santos, código: 2069922
//Leticia de Oliveira Coleto, código: 2057336

//inclusão bibliotecas
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <locale>
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

    //declarações de variáveis
    string origem = "x";
    string destino = "t";
    map<string, string> caminho;
    int custo;
    
    //chamada da função para ler arquivos dos grafos, passando se ele possui peso ou não
    lerArquivoGrafo("grafos/g1.txt", g1, false);
    lerArquivoGrafo("grafos/g2.txt", g2, false);
    lerArquivoGrafo("grafos/g3.txt", g3, true);

    cout <<"--------------------------------------------------------" << endl;
    cout << "TRABALHO 2 - ANALISE DE ALGORITMOS" << endl;
    cout << "Realizado por: Fernanda (2069922) e Leticia (2057336)" << endl;
    cout <<"--------------------------------------------------------\n" << endl;

    //impressão das listas de adjacência dos três grafos
    cout << "1. LISTAS DE ADJACENCIA DE CADA GRAFO" << endl;
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
    cout << "2. BUSCA EM LARGURA" << endl;
    cout << "Busca em Largura para G1 a partir do vertice 'b': ";
    g1.buscaEmLargura("b");
    cout << endl;

    cout << "\n3. BUSCA EM PROFUNDIDADE" << endl;
    cout << "Busca em Profundidade para G2 a partir do vertice 'a': ";
    g2.buscaEmProfundidade("a");
    cout << endl;

    cout << "\n4. ALGORITMO MINIMO (DIJKSTRA)" << endl;
    g3.menorCaminhoDijkstra(origem, destino, caminho, custo);

    return 0;
}