# Trabalho 2 - Análise de Algoritmos

## Integrantes
Fernanda Bonfim Santos, código: 2069922
Leticia de Oliveira Coleto, código: 2057336

## Documentação do Código

### Arquivo Aresta.h
#### Descrição
O arquivo Aresta.h define a estrutura Aresta, que representa uma aresta do grafo. Cada uma possui uma origem, destino e, além disso, pode possuir um peso.

#### Estrutura
*Struct Aresta: define a Aresta com os atributos:
    * Origem: string representando o vértice de origem da aresta.
    * Destino: string representando o vértice de destino da aresta.
    * Peso: inteiro representando o peso da aresta.
*Construtor: responsável por inicializar uma aresta com uma origem, detino e peso (opcional).

### Arquivo Grafo.h
#### Descrição
O arquivo Grafo.h define a estrutura Grafo. Ele pode ser orientado ou não, sendo determinado pelo membro de dados "orientado". Vale ressaltar que o grafo é representado por uma lista de adjacência, que consiste em um "map" de strings para Arestas. Além do mais, há um "map", sendo ele o "visitado", que rastreia quais vértices foram visitados durante as buscas. 

#### Estrutura
* Classe Grafo: define a classe Grafo com os atributos e métodos:
    * Atributos:
        * Orientado: booleano indicando se o grafo é orientado ou não.
        * ListaAdjacencia: mapa que mapeia cada vértice para um vetor de Arestas.
        * Visitado: mapa que verifica os vértices visitados durante as buscas.
    *Métodos:
        * Grafo: construtor da classe Grafo.
        * AdicionarArestas: adiciona uma aresta ao grafo. 
        * ImprimirListaAdjacencia: imprime a lista de adjacência do grafo.
        * BuscaEmProfundidade: realiza a busca em profundidade a partir de um vértice.
        * BuscaEmLargura: realiza a busca em largura a partir de um vértice.
        * OrdenarVertices: ordena os vértices do grafo para realizar as buscas corretamente.

### Arquivo Grafo.cpp
#### Descrição
O arquivo Grafo.cpp implementa os métodos da classe Grafo (definida em Grafo.h), sendo eles o método de adicionar arestas, busca em profundidade, em largura e a ordenação dos vértices.

#### Estrutura
* Grafo: construtor da classe Grafo.
* AdicionarAresta: este método é responsável por adicionar uma aresta ao grafo. Sobre a lógica por trás do mesmo, basicamente, ele primeiramente adiciona uma aresta do vértice de origem ao de destino (isso é feito inserindo um novo objeto que representa a aresta na lista de adjacência, com os parâmetros origem, destino e peso). Posteriormente, ele irá verificar se o grafo é orientado ou não. Caso não for, ele irá adicionar também a aresta inversa (exemplificando, quando temos uma matriz orientada, temos A -> B, contudo, quando ela não é orientada, temos tanto A -> B quanto B -> A, sendo a aresta inversa), que conecta os mesmos dois vértices na ordem inversa.
* OrdenarVertices: implementação do método bubble sort para ordenar as arestas com base no destino. Ele compara o destino de cada aresta com o da próxima e troca elas de posição se estiverem fora de ordem, fazendo isso sucessicamente até que todas estejam ordenadas.
* ImprimirListaAdjacencia: método que percorre a lista de adjacência do grafo e imprime uma lista dos vértices que estão conectados entre si, juntamente com os pesos e conexões.
* BuscaEmLargura: este método visita todos os vértices em largura, iniciando pelo vértice inicial e visitando todos os conectados a ele. Nele, é utilizado a estrutura de fila para controlar a ordem de visitação, de forma que garanta que os mais próximos sejam visitados primeiro antes de ir aos mais distantes.
* BuscaEmProfundidade: método que percorre o grafo a partir de um vértice inicial de forma recursiva, visitando todos os vértices conectados a ele em profundidade.

### Arquivo main.cpp
#### Descrição
O arquivo main.cpp é a estrutura principal do programa. Nele, são criadas as instâncias de objeto "Grafo" e também é realizada a leitura dos arquivos de entrada para a construção dos grafos. Por fim, ele exibe as listas de adjacências e os resultados das buscas.

#### Estrutura
* LerArquivoGrafo: aqui é realizada a leitura dos arquivos de texto que contém as informações do grafo (origem, destino e peso). Para cada linha, é adicionada uma aresta ao grafo utilizando os dados do arquivo. Isso acontece repetidamente até que todas as linhas tenham sido lidas.