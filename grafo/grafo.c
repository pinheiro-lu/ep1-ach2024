#include <string.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../hash/hash.h"

#include "grafo.h"

// Funções criadas pelo grupo

Grafo * inicializaGrafo(int n) {
	Grafo * grafo = (Grafo *) malloc(sizeof(Grafo));

	grafo->nomeVertice = (char **) malloc(sizeof(char *) * n);
	grafo->adj = (Lista **) malloc(sizeof(Lista *) * n);
	grafo->A = 0;
	grafo->V = n;
	grafo->d = (int *) malloc(sizeof(int)* n);
	grafo->f = (int *) malloc(sizeof(int)* n);
	grafo->pai = (int *) malloc(sizeof(int)* n);
	grafo->cor = (int *) malloc(sizeof(int)* n);
	grafo->elemento = (ElementoHash *) malloc(sizeof(ElementoHash)*n);

	return grafo;
}

int encontraVertice(Grafo * grafo, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	return buscaHash(grafo, nomeVerticeAdjacente);
}

void ajustaVerticesAdjacentes(Grafo * grafo) {
	for (int i = 0; i < grafo->V; i++) {
		insereHash(grafo, grafo->nomeVertice[i], i);
	}

	for (int i = 0; i < grafo->V; i++) {
		Adj * aux = grafo->adj[i]->primeiro;

		while (aux) {
			aux->vertice = encontraVertice(grafo, aux->nomeVerticeAdjacente);
			aux = aux->prox;
		}

	}
}

void insereListaTransposta(Lista * listaArestas, int indiceAdjacente, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	insereLista(listaArestas, nomeVerticeAdjacente);
	
	listaArestas->primeiro->vertice = indiceAdjacente;
}

Lista ** tranposicaoArestas(Grafo * grafo) {
	Lista ** arestasTranspostas = (Lista **) malloc(sizeof(Lista *) * grafo->V);

	for (int i = 0; i < grafo->V; i++) {
		arestasTranspostas[i] = (Lista *) malloc(sizeof(Lista));
	}

	for (int i = 0; i < grafo->V; i++) {	
		Adj * aux = grafo->adj[i]->primeiro;
		while (aux) {
			insereListaTransposta(arestasTranspostas[aux->vertice], i, grafo->nomeVertice[i]);
			aux = aux->prox;
		}
	}

	return arestasTranspostas;
}

int contaArvores(Grafo * grafo) {
	int soma = 0;
	for (int i = 0; i < grafo->V; i++) {
		if(grafo->pai[i] == i) soma++;
	}

	return soma;
}
