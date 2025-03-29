#ifndef PROGETTO_PROGETTO_H
#define PROGETTO_PROGETTO_H
#include <list>
#include "Edge.h"
#include <unordered_map>
#include <fstream>
#include "Node.h"

using namespace std;

// Classe Progetto per rappresentare il progetto del grafo
class Progetto {
private:
    list<Edge> edges; // Lista degli archi del grafo
    unordered_map<Node, size_t> symbolMap; // Mappa per la simbolizzazione dei nodi
    int r, regionsCost, railsCost, railsNum, numV; // Variabili di costo e contatori
public:
    explicit Progetto(const string& fileName); // Costruttore che utilizza un file
    list<Edge> kruskal(); // Funzione per eseguire l'algoritmo di Kruskal
    int getRegionsCost(); // Getter per il costo delle regioni
    int getRailsCost(); // Getter per il costo delle ferrovie
    int getRailsNum(); // Getter per il numero di ferrovie
};

#endif //PROGETTO_PROGETTO_H
