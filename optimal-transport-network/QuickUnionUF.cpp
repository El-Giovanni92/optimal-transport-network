#include "QuickUnionUF.h"

// Implementazione del costruttore della classe QuickUnionUF
QuickUnionUF::QuickUnionUF(int n) {
    parent.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i; // Inizializzazione: ogni nodo è il proprio genitore
    }
}

// Implementazione della funzione root con compressione dei percorsi
int QuickUnionUF::root(int p) {
    while (p != parent[p]) {
        p = root(parent[p]); // Path Compression
    }
    return p;
}

// Implementazione della funzione unite
void QuickUnionUF::unite(int p, int q) {
    int rootP = root(p);
    int rootQ = root(q);

    if (rootP == rootQ) return;

    // Uniamo l'albero più piccolo sotto la radice dell'albero più grande
    if (sz[rootP] < sz[rootQ]) {
        parent[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    } else {
        parent[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    }
}

// Implementazione della funzione connected
bool QuickUnionUF::connected(int p, int q) {
    return root(p) == root(q);
}
