#ifndef PROGETTO_EDGE_H
#define PROGETTO_EDGE_H

// Classe Edge per rappresentare un arco del grafo con nodo di partenza, nodo di arrivo e peso
class Edge {
private:
    int fromNode;
    int toNode;
    int weight;
public:
    Edge(int fromNode, int toNode, int weight); // Costruttore
    bool operator<(const Edge& other) const; // Operatore di confronto per ordinamento

    int getFromNode() const; // Getter per il nodo di partenza
    int getToNode() const; // Getter per il nodo di arrivo
    int getWeight() const; // Getter per il peso dell'arco
};

#endif //PROGETTO_EDGE_H
