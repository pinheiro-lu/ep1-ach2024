#include <string.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "ordenacao.h"

// Funções criadas pelo grupo. Lógica adaptada do material de AED II

typedef struct {
	int f;
	int indice;
} Pair;

int compare(const void *l, const void *r) {
	return (((Pair*)r)->f - ((Pair *)l)->f);
}

void ordenacaoTopologica (Grafo * grafo){
	Pair * pair = (Pair *) malloc(sizeof(Pair) * grafo->V);

	for (int i = 0; i < grafo->V; i++) {
		pair[i].f = grafo->f[i];
		pair[i].indice = i;
	}
	qsort(pair, grafo->V, sizeof(Pair), compare);

	Grafo * novo = inicializaGrafo(grafo->V);

	for (int i = 0; i < grafo->V; i++) {
		novo->adj[i] = grafo->adj[pair[i].indice];
		novo->cor[i] = grafo->cor[pair[i].indice];
		novo->d[i] = grafo->d[pair[i].indice];
		novo->f[i] = grafo->f[pair[i].indice];
		novo->pai[i] = grafo->pai[pair[i].indice];
		novo->nomeVertice[i] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
		strcpy(novo->nomeVertice[i], grafo->nomeVertice[pair[i].indice]);
	}

	novo->A = grafo->A;
	novo->V = grafo->V;

	ajustaVerticesAdjacentes(novo);

	*grafo = *novo;
}
