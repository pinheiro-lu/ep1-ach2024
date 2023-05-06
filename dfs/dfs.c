#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "dfs.h"

#define BRANCO 0
#define CINZA 1
#define PRETO 2

int time;

void DFSvisit (Grafo * grafo, Lista ** adj, int u, int pai){
	grafo->cor[u] = CINZA;
	time++;
	grafo->d[u] = time;

	Adj * aux = adj[u]->primeiro;
	while (aux) {
		if(grafo->cor[aux->vertice] == BRANCO) {
			grafo->pai[aux->vertice] = pai;
			DFSvisit(grafo, adj, aux->vertice, pai);
		}
		aux = aux->prox;
	}
	grafo->cor[u] = PRETO;
	time++;
	grafo->f[u] = time;
}

void DFS (Grafo * grafo, Lista ** adj){
	for (int u = 0; u < grafo->V; u++){
		grafo->cor[u] = BRANCO;
		grafo->pai[u] = u;
	}
	time = 0;
	for (int u = 0; u < grafo->V; u++){
		if (grafo->cor[u] == BRANCO)
			DFSvisit(grafo, adj, u, u);
	}
}
