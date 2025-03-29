#include "Edge.h"

// Implementazione del costruttore della classe Edge
Edge::Edge(int fromNode, int toNode, int weight) {
    this->fromNode = fromNode;
    this->toNode = toNode;
    this->weight = weight;
}

// Implementazione dell'operatore di confronto
bool Edge::operator<(const Edge& other) const {
    return weight < other.weight;
}

// Implementazione del getter per fromNode
int Edge::getFromNode() const {
    return fromNode;
}

// Implementazione del getter per toNode
int Edge::getToNode() const {
    return toNode;
}

// Implementazione del getter per weight
int Edge::getWeight() const {
    return weight;
}