#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "dfs.h"

// Funções adaptadas do material disponibilizado para as aulas de AED II

#define BRANCO 0
#define CINZA 1
#define PRETO 2

int tempo;

void DFSvisit (Grafo * grafo, Lista ** adj, int u, int pai){
	grafo->cor[u] = CINZA;
	tempo++;
	grafo->d[u] = tempo;

	Adj * aux = adj[u]->primeiro;
	while (aux) {
		if(grafo->cor[aux->vertice] == BRANCO) {
			grafo->pai[aux->vertice] = pai;
			DFSvisit(grafo, adj, aux->vertice, pai);
		}
		aux = aux->prox;
	}
	grafo->cor[u] = PRETO;
	tempo++;
	grafo->f[u] = tempo;
}

void DFS (Grafo * grafo, Lista ** adj){
	for (int u = 0; u < grafo->V; u++){
		grafo->cor[u] = BRANCO;
		grafo->pai[u] = u;
	}
	tempo = 0;
	for (int u = 0; u < grafo->V; u++){
		if (grafo->cor[u] == BRANCO)
			DFSvisit(grafo, adj, u, u);
	}
}
