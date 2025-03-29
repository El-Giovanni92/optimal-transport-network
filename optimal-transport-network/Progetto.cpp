#include "Progetto.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "QuickUnionUF.h"

using namespace std;

// Implementazione del costruttore che utilizza un file
Progetto::Progetto(const string& fileName) {
    size_t fromNode, toNode, weight;
    string line, number1, number2;
    ifstream file(fileName);
    this->regionsCost = 0;
    this->railsCost = 0;
    this->railsNum = 0;
    if (file.is_open()) {

        getline(file, line);//Legge la prima riga
        istringstream attributeStream(line);//Crea un flusso di caratteri a partire dalla linea letta.
        //In questo modo è possibile analizzare la linea spezzandola in token grazie ad un delimitatore.
        //In altre parole: simulazione del metodo split di java per le stringhe
        getline(attributeStream, number1, ' ');//Estrae numero di vertici
        getline(attributeStream, number2, ' ');//Estrae la distanza "r"
        //Vincoli su "n" (1 <= n <= 100) ed "r" (0 <= r <= 4000)
        if (stoi(number1)<1 || stoi(number1)>100) throw runtime_error("Il numero di nodi deve essere compreso tra 1 e 100");
        if (stoi(number2)<0 || stoi(number2)>4000) throw runtime_error("Il valore \"r\" deve essere compreso tra 0 e 4000");
        this->numV = stoi(number1);
        this->r = stoi(number2);
        //Legge tutte le righe del file a partire dalla seconda
        while (getline(file, line)) {
            auto position = file.tellg(); //Ottiene la posizione del puntatore all'interno del file
            istringstream fromNodeStream(line);//Come prima, si crea un flusso per analizzare la riga letta
            getline(fromNodeStream, number1, ' ');//Estrae la coordinata x del vertice
            getline(fromNodeStream, number2, ' ');//Estrae la coordinata y del vertice
            //Vincolo sulle coordinate x e y (0 <= x,y <= 1000)
            if (stoi(number1)<0 || stoi(number1)>1000 || stoi(number2)<0 || stoi(number2)>1000) throw runtime_error("Le coordinate x e y di ogni nodo devono essere comprese tra 0 e 1000");
            Node fromNodePoint(stoi(number1), stoi(number2));
            auto iterator = this->symbolMap.find(fromNodePoint); //Ricerca il Nodo all'interno della mappa
            if (iterator == this->symbolMap.end()) { //Verifica se il Nodo é presente all'interno della mappa
                fromNode = (this->symbolMap.size() - 1) + 1;
                this->symbolMap.emplace(fromNodePoint, fromNode); //Aggiunge la coppia Nodo-Indice alla mappa
            } else {
                fromNode = iterator->second; //Ottiene l'indice del Nodo già presente nella mappa
            }
            //Legge tutti i nodi scritti nelle righe successive a quella letta per calcolare tutte le possibili distanze
            // tra questi nodi e il nodo letto precedentemente
            while (getline(file, line)) {
                istringstream toNodeStream(line);
                getline(toNodeStream, number1, ' ');
                getline(toNodeStream, number2, ' ');
                //Vincolo sulle coordinate x e y (0 <= x,y <= 1000)
                if (stoi(number1)<0 || stoi(number1)>1000 || stoi(number2)<0 || stoi(number2)>1000) throw runtime_error("Le coordinate x e y di ogni nodo devono essere comprese tra 0 e 1000");
                Node toNodePoint(stoi(number1), stoi(number2));
                iterator = this->symbolMap.find(toNodePoint);
                if (iterator == this->symbolMap.end()) {
                    toNode = (this->symbolMap.size() - 1) + 1;
                    this->symbolMap.emplace(toNodePoint, toNode);
                } else {
                    toNode = iterator->second;
                }
                // Calcola il peso dell'arco come la distanza euclidea tra i due nodi
                weight = (int)sqrt(
                        pow(fromNodePoint.getX() - toNodePoint.getX(), 2) +
                        pow(fromNodePoint.getY() - toNodePoint.getY(), 2));
                this->edges.emplace_back(fromNode, toNode, weight); //Aggiunge l'arco pesato alla lista
            }
            file.clear(); //Pulisce le flag del file
            file.seekg(position, std::ios_base::beg); //Posiziona il puntatore all'interno del file all'inizio della riga successiva
        }
        this->symbolMap.clear(); //Svuota la mappa
        for (Edge edge : this->edges) {
            cout << to_string(edge.getFromNode()) + " - " + to_string(edge.getToNode()) + " : " + to_string(edge.getWeight()) << endl;
        }
    } else {
        throw runtime_error("Non è stato possibile leggere il file ed eseguire il programma.\n");
    }
}

// Implementazione dell'algoritmo di Kruskal
list<Edge> Progetto::kruskal() {
    this->edges.sort(); // Ordina gli archi per peso
    QuickUnionUF uf(this->numV); // Inizializza la struttura Union-Find
    list<Edge> mst; // Lista per l'albero ricoprente minimo (MST)
    for (const auto& edge : this->edges) {
        if (!uf.connected(edge.getFromNode(), edge.getToNode())) {
            uf.unite(edge.getFromNode(), edge.getToNode());
            mst.push_back(edge);
        }
    }
    // Calcola i costi delle regioni e delle ferrovie
    for (const auto& edge : mst) {
        if (edge.getWeight() > this->r) {
            this->railsCost += edge.getWeight();
            this->railsNum++;
        } else {
            this->regionsCost += edge.getWeight();
        }
    }
    return mst;
}

// Implementazione del getter per regionsCost
int Progetto::getRegionsCost() {
    return this->regionsCost;
}

// Implementazione del getter per railsCost
int Progetto::getRailsCost() {
    return this->railsCost;
}

// Implementazione del getter per railsNum
int Progetto::getRailsNum() {
    return this->railsNum;
}
