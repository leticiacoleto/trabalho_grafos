//inclusão das bibliotecas
#include "Grafo.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//construtor Grafo e inicialização do atributo orientado
Grafo::Grafo(bool orientado) : orientado(orientado) {}

void Grafo::adicionarAresta(const string& origem, const string& destino, int peso) {
    listaAdjacencia[origem].emplace_back(origem, destino, peso); //adiciona uma aresta do vértice 'origem' ao vértice 'destino'

    if (!orientado) { //caso o grafo não for orientado, adiciona também a aresta inversa
        listaAdjacencia[destino].emplace_back(destino, origem, peso);
    }
}

void Grafo::imprimirListaAdjacencia() const {
    for (const auto& vertice : listaAdjacencia) { //itera sobre todos os vértices na lista de adjacência
        cout << vertice.first << " -> ";
        for (const auto& aresta : vertice.second) { //itera sobre todas as arestas do vértice
            cout << aresta.destino << "(" << aresta.peso << ") ";
        }
        cout << endl;
    }
}

void Grafo::ordenarVertices(vector<Aresta>& arestas) {
    int i, j;
    int n = arestas.size();
    for (i = 0; i < n-1; i++) {      
        for (j = 0; j < n-i-1; j++) {
            if (arestas[j].destino > arestas[j+1].destino) {
                Aresta temp = arestas[j];
                arestas[j] = arestas[j+1];
                arestas[j+1] = temp;
            }
        }
    }
}

void Grafo::buscaEmLargura(const string& v) {
    for (auto& estado : visitado) {
        estado.second = false; //zera todos os vértices visitados
    }

    queue<string> fila; //inicializa uma fila para a busca em largura
    visitado[v] = true; //marca o vértice inicial como visitado
    fila.push(v); //adiciona o vértice inicial a fila

    while (!fila.empty()) { //enquanto a fila não estiver vazia, continua a busca
        string verticeAtual = fila.front(); 
        fila.pop(); //remove o vértice da frente da fila
        cout << verticeAtual << " ";

        vector<Aresta>& arestas = listaAdjacencia[verticeAtual];
        ordenarVertices(arestas);

        for (const auto& aresta : listaAdjacencia[verticeAtual]) { //itera sobre todas as arestas do vértice atual
            string verticeDestino = aresta.destino; //obtém o destino da aresta
            if (!visitado[verticeDestino]) { //se o destino não foi visitado, marca como visitado e adiciona à fila
                visitado[verticeDestino] = true;
                fila.push(verticeDestino);
            }
        }
    }
}

void Grafo::buscaEmProfundidade(const string& v) { 
    visitado[v] = true; //marca v como visitado
    cout << v << " "; //imprime o vértice visitado

    for (auto& arestas : listaAdjacencia) { //ordena os vértices
        ordenarVertices(arestas.second);
    }

    for (const auto& aresta : listaAdjacencia[v]) { //percorre todas as arestas do vértice atual
        if (!visitado[aresta.destino]) { //se o destino da aresta não foi visitado, realiza a busca em profundidade a partir desse destino
            buscaEmProfundidade(aresta.destino);
        }
    }
}