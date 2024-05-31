//inclusão das bibliotecas
#include "Grafo.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

Grafo::Grafo(bool orientado) : orientado(orientado) {} //construtor Grafo e inicialização do atributo orientado

void Grafo::adicionarAresta(const string& origem, const string& destino, int peso) { //método que adiciona arestas no grafo
    listaAdjacencia[origem].emplace_back(origem, destino, peso); //adiciona um novo elemento no final da lista de adjacencia
    if (!orientado) {
        listaAdjacencia[destino].emplace_back(destino, origem, peso);
    }
}

void Grafo::imprimirListaAdjacencia() const {
    for (const auto& vertice : listaAdjacencia) {
        cout << vertice.first << " -> ";
        for (const auto& aresta : vertice.second) {
            cout << aresta.destino << "(" << aresta.peso << ") ";
        }
        cout << endl;
    }
}

void Grafo::buscaEmProfundidade(const string& v) { 
    visitado[v] = true; //marca v como visitado
    cout << v << " "; //imprime o vértice visitado
    
    for (const auto& aresta : listaAdjacencia[v]) {
        if (!visitado[aresta.destino]) {
            buscaEmProfundidade(aresta.destino);
        }
    }
}

void Grafo::ordenarVertices() { // Remova o parâmetro aqui
    for (auto& arestas : listaAdjacencia) { // Ordenar cada vetor de arestas em listaAdjacencia
        sort(arestas.second.begin(), arestas.second.end(), [](const Aresta& a, const Aresta& b) {
            return a.destino < b.destino;
        });
    }
}

void Grafo::buscaEmLargura(const string& v) {
    for (auto& estado : visitado) {
        estado.second = false; // Zera todos os vértices visitados
    }

    queue<string> fila;
    visitado[v] = true;
    fila.push(v);

    while (!fila.empty()) {
        string u = fila.front();
        fila.pop();
        cout << u << " ";

        for (const auto& aresta : listaAdjacencia[u]) {
            string w = aresta.destino;
            if (!visitado[w]) {
                visitado[w] = true;
                fila.push(w);
            }
        }
    }
}