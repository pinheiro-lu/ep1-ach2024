#include <string.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "lista.h"

Lista * inicializaLista() {
	Lista * adj = (Lista *) malloc(sizeof(Lista));
	adj->primeiro = NULL;

	return adj;
}

void insereLista(Lista * adj, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	Adj * novo = (Adj *) malloc(sizeof(Adj));
	novo->nomeVerticeAdjacente = (char *) malloc(sizeof(char)* NUM_CARACTERES_VERTICE);
	strcpy(novo->nomeVerticeAdjacente, nomeVerticeAdjacente);
	novo->prox = adj->primeiro;
	adj->primeiro = novo;
}
