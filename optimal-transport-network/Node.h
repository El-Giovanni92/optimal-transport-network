#ifndef PROGETTO_NODE_H
#define PROGETTO_NODE_H
#include <functional>

// Classe Node per rappresentare un nodo del grafo con coordinate x e y
class Node {
private:
    int x;
    int y;
public:
    Node(int x, int y); // Costruttore
    bool operator==(const Node& other) const; // Operatore di uguaglianza
    int getX() const; // Getter per la coordinata x
    int getY() const; // Getter per la coordinata y
};

// Specializzazione dello std::hash per la classe Node
namespace std {
    template <>
    struct hash<Node> {
        size_t operator()(const Node& node) const {
            // Combina gli hash di x e y in modo da ottenere un hash univoco per Node
            return hash<int>()(node.getX()) ^ (hash<int>()(node.getY()) << 1);
        }
    };
}

#endif //PROGETTO_NODE_H
