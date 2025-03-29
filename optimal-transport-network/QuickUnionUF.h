#ifndef PROGETTO_QUICKUNIONUF_H
#define PROGETTO_QUICKUNIONUF_H

#include <vector>

// Classe QuickUnionUF per rappresentare una struttura Union-Find con compressione dei percorsi
class QuickUnionUF {
private:
    std::vector<int> parent; // Vettore dei genitori
    std::vector<int> sz; // Vettore delle dimensioni dei sottoalberi
    int root(int p); // Funzione per trovare la radice del nodo p
public:
    QuickUnionUF(int n); // Costruttore
    void unite(int p, int q); // Funzione per unire due insiemi
    bool connected(int p, int q); // Funzione per verificare se due nodi sono connessi
};

#endif //PROGETTO_QUICKUNIONUF_H
