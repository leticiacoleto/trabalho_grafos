#ifndef GRAFO_H //se GRAFO_H não estiver definido, o código abaixo será executado, caso contrário, será ignorado
#define GRAFO_H //se ifndef for verdadeiro, ARESTA_H é definido, evitando várias inclusões do mesmo cabeçalho

//inclusão das bibliotecas
#include <string>
#include <vector>
#include <map>
#include "Aresta.h"

using namespace std;

class Grafo {
public:
    Grafo(bool orientado = false); //construtor da classe Grafo, inicializado para que não seja orientado
    void adicionarAresta(const string& origem, const string& destino, int peso = 0);
    void imprimirListaAdjacencia() const; 
    void buscaEmProfundidade(const string& v);
    void buscaEmLargura(const string& v); 
    void ordenarVertices(vector<Aresta>& arestas); 
private:
    bool orientado; //variável booleana que indica se o grafo é orientado ou não
    map<string, vector<Aresta>> listaAdjacencia; //mapeia cada vértice (string) para um vetor de Arestas (struct presente no arquivo aresta.h)
    map<string, bool> visitado; //verifica os vértices visitados  
};

#endif