#ifndef GRAFO_H //se GRAFO_H não estiver definido, o código abaixo será executado, caso contrário, será ignorado
#define GRAFO_H //se ifndef for verdadeiro, ARESTA_H é definido, evitando várias inclusões do mesmo cabeçalho

//inclusão das bibliotecas
#include <string>
#include <vector>
#include <map>
#include "Aresta.h"

using namespace std;

class Grafo {
public: //métodos públicos
    Grafo(bool orientado = false); //construtor da classe Grafo, inicializado para que não seja orientado
    void adicionarAresta(const string& origem, const string& destino, int peso = 0); //método que adiciona uma aresta ao grafo
    void imprimirListaAdjacencia() const; //exibe a lista de adjacência e este método não modifica o estado do objeto (por isso o const)
    void buscaEmProfundidade(const string& v); //método que realiza a busca por profundidade
    void buscaEmLargura(const string& v); //método que realiza a busca por largura
    void ordenarVertices(); //método que ordena os vértices, para fazermos as bucas em ordem lexicográfica
private: //métodos privados
    bool orientado; //variável booleana que indica se o grafo é orientado ou não
    map<string, vector<Aresta>> listaAdjacencia; //mapeia cada vértice (string) para um vetor de Arestas (struct presente no arquivo aresta.h)
    map<string, bool> visitado; //verifica os vértices visitados  
};

#endif