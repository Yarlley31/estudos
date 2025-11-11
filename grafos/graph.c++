#include <iostream>
#include <vector>
#include <list>

// estrutura do node da lista de ajacencias
class Graph {
private:
    int num_vertices;

    std::vector<std::list<int>> list_adj;

public:
    Graph(int V) {
        num_vertices = V;
        list_adj.resize(V);
    }

    void addAresta(int origin, int destinattion) {
        // Adiciona 'destino' a lista de 'origem'
        list_adj[origin].push_back(destinattion);

        // Adiciona 'origem' a lista de 'destino'
        list_adj[destinattion].push_back(origin);
    }

    void printGraph() {
        for (int v = 0; v < num_vertices; v++) {
            std::cout << "Vertice " << v << ":";

            for (int vizinho : list_adj[v]) {
                std::cout << " -> " << vizinho;
            }

            std:: cout << "\n";
        }
    }
};

int main() {
    Graph grafo(5);

    grafo.addAresta(0, 1);
    grafo.addAresta(0, 4);
    grafo.addAresta(1, 2);
    grafo.addAresta(1, 3);
    grafo.addAresta(2, 3);

    grafo.printGraph();

    return 0;
}