#include "Node.h"

// Implementazione del costruttore della classe Node
Node::Node(int x, int y) {
    this->x = x;
    this->y = y;
}

// Implementazione dell'operatore di uguaglianza
bool Node::operator==(const Node &other) const {
    return this->getX() == other.getX() && this->getY() == other.getY();
}

// Implementazione del getter per x
int Node::getX() const {
    return x;
}

// Implementazione del getter per y
int Node::getY() const {
    return y;
}