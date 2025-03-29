#include <iostream>
#include <list>
#include "Progetto.h"
#include "Edge.h"
using namespace std;

int main() {
    cout << "Graph:" << endl;
    /*Progetto progetto;
    list<Edge> mst = progetto.kruskal();

    cout << "Edges in MST:" << endl;
    for (const auto& edge : mst) {
        cout << edge.getFromNode() << " - " << edge.getToNode() << " : " << edge.getWeight() << endl;
    }

    cout << "Number of Regions: " << progetto.getRailsNum() + 1 << endl;
    cout << "Regions cost: " << progetto.getRegionsCost() << endl;
    cout << "Rails cost: " << progetto.getRailsCost() << endl;*/

    Progetto progetto("cities.txt");
    list<Edge> mst = progetto.kruskal();

    cout << "Edges in MST:" << endl;
    for (const auto& edge : mst) {
        cout << edge.getFromNode() << " - " << edge.getToNode() << " : " << edge.getWeight() << endl;
    }

    cout << "Number of Regions: " << progetto.getRailsNum() + 1 << endl;
    cout << "Regions cost: " << progetto.getRegionsCost() << endl;
    cout << "Rails cost: " << progetto.getRailsCost() << endl;

    return 0;
}