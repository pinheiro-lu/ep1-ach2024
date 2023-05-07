#include <string.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "lista.h"

// Funções criadas pelo grupo

Lista * inicializaLista() {
	Lista * adj = (Lista *) malloc(sizeof(Lista));
	adj->primeiro = NULL;

	return adj;
}



void insereNomeLista(Lista * adj, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	Adj * novo = (Adj *) malloc(sizeof(Adj));
	novo->nomeVerticeAdjacente = (char *) malloc(sizeof(char)* NUM_CARACTERES_VERTICE);
	strcpy(novo->nomeVerticeAdjacente, nomeVerticeAdjacente);
	novo->prox = adj->primeiro;
	adj->primeiro = novo;
}

void insereLista(Lista * listaArestas, int indiceAdjacente, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	insereNomeLista(listaArestas, nomeVerticeAdjacente);
	
	listaArestas->primeiro->vertice = indiceAdjacente;
}
