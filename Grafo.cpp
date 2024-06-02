//Fernanda Bonfim Santos, código: 2069922
//Leticia de Oliveira Coleto, código: 2057336

//inclusão das bibliotecas
#include "Grafo.h"
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

//construtor Grafo e inicialização do atributo orientado
Grafo::Grafo(bool orientado) : orientado(orientado) {}

void Grafo::adicionarAresta(const string& origem, const string& destino, int peso) {
    listaAdjacencia[origem].push_back(Aresta(origem, destino, peso)); // substituição de emplace_back por push_back

    if (!orientado) {
        listaAdjacencia[destino].push_back(Aresta(destino, origem, peso)); // substituição de emplace_back por push_back
    }
}

void Grafo::imprimirListaAdjacencia() const {
    for (const auto& vertice : listaAdjacencia) { //itera sobre todos os vértices na lista de adjacência
        cout << vertice.first << ": ";
        for (const auto& aresta : vertice.second) { //itera sobre todas as arestas do vértice
            cout << aresta.destino << "(" << aresta.peso << ") ";
        }
        cout << endl;
    }
}

void Grafo::ordenarVertices(vector<Aresta>& arestas) { //método que faz a ordenação dos vértices por meio do Bubble Sort
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

void Grafo::inverterCaminho(const string& origem, const string& destino, const map<string, string>& caminho, vector<string>& caminhoInvertido) {
    caminhoInvertido.push_back(destino); //adiciona o destino ao final do vetor

    for (string vertice = destino; vertice != origem; vertice = caminho.at(vertice)) { //percorre o caminho mínimo e armazena os vértices em ordem inversa, para exibição
        caminhoInvertido.push_back(caminho.at(vertice));
    }

    reverse(caminhoInvertido.begin(), caminhoInvertido.end()); //inverte a ordem dos vértices (reverse)
}

void Grafo::menorCaminhoDijkstra(const string& origem, const string& destino, map<string, string>& caminho, int& custo) {
    map<string, int> distancia; // armazenar a distância mínima de cada vértice até a origem

    for (const auto& par : listaAdjacencia) {
        distancia[par.first] = INT_MAX; // inicializa as distâncias como infinito 
        visitado[par.first] = false; // inicializa os vértices como não visitados
    }
    
    distancia[origem] = 0; // distância da origem até ela mesma é 0

    string verticeAtual = origem;
    
    while (!verticeAtual.empty()) { // enquanto houverem vértices a serem visitados

        visitado[verticeAtual] = true; // marca o vértice atual como visitado

        int menorDistancia = INT_MAX;
        
        string proximoVertice;

        for (const auto& aresta : listaAdjacencia[verticeAtual]) { // percorre todas as arestas do vértice atual
            int novaDistancia = distancia[verticeAtual] + aresta.peso; // calcula a nova distância até o destino da aresta
   
            if (novaDistancia < distancia[aresta.destino]) { // se a nova distância for menor que a distância atual
                distancia[aresta.destino] = novaDistancia; 
                caminho[aresta.destino] = verticeAtual;
            }
        }

        for (const auto& par : distancia) { 
            if (!visitado[par.first] && par.second < menorDistancia) { // verifica se o vértice ainda não foi visitado e se a distância é menor que a menor distância encontrada até agora
                menorDistancia = par.second;
                proximoVertice = par.first;
            }
        }

        verticeAtual = proximoVertice;
    }

    custo = distancia[destino]; //atualiza o custo total do menor caminho encontrado
    cout << "Custo total do menor caminho de '" << origem << "' para '" << destino << "': " << custo << endl;

    vector<string> caminhoInvertido;
    inverterCaminho(origem, destino, caminho, caminhoInvertido); //chamada da função que inverte o caminho para exibição

    cout << "Caminho mínimo encontrado entre '" << origem << "' e '" << destino << "': ";
    bool ultimoVertice = false;
    for (const string& vertice : caminhoInvertido) {
        if (ultimoVertice) {
            cout << " -> ";
        }
        cout << vertice;
        ultimoVertice = true;   
    }
}