//Fernanda Bonfim Santos, código: 2069922
//Leticia de Oliveira Coleto, código: 2057336

#ifndef ARESTA_H //se ARESTA_H não estiver definido, o código abaixo será executado, caso contrário, será ignorado
#define ARESTA_H //se ifndef for verdadeiro, ARESTA_H é definido, evitando várias inclusões do mesmo cabeçalho

//inclusão biblioteca
#include <string>

using namespace std;

struct Aresta { //define a struct Aresta com origem, destino e peso
    string origem; 
    string destino; 
    int peso;       

    Aresta(const string& vertice_origem, const string& vertice_destino, int peso_aresta = 0) 
        : origem(vertice_origem), destino(vertice_destino), peso(peso_aresta) {} //construtor da struct Aresta que inicializa origem, destino e peso
};

#endif