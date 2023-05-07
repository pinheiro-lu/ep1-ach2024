#include <stdio.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "entrada-saida.h"

// Funções criadas pelo grupo

void lerLinhaVertice (char linha[NUM_CARACTERES_LINHA], Grafo * grafo, int vertice) {
	int offset, numCaracteresLidos;

	grafo->nomeVertice[vertice] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
	grafo->adj[vertice] = inicializaLista();

	sscanf(linha, "%[^:]:%n", grafo->nomeVertice[vertice], &numCaracteresLidos);

	offset = numCaracteresLidos;
		
	char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE];

	while(sscanf(linha + offset, " %[^;];%n", nomeVerticeAdjacente, &numCaracteresLidos) == 1) {
		insereNomeLista(grafo->adj[vertice], nomeVerticeAdjacente);
		grafo->A++;
		offset += numCaracteresLidos;
	}
}

void imprimeSaida (Grafo * sccs){
	puts (sccs->V == 1 ? "Sim" : "Não");
	printf ("%d\n", sccs->V);
	for (int i = 0; i < sccs->V; i++) {
		printf("%s ", sccs->nomeVertice[i]);
	}
	puts("");
	for (int i = 0; i <sccs->V; i++){
		printf ("%s: ", sccs->nomeVertice[i]);
		for (Adj * aux = sccs->adj[i]->primeiro; aux; aux = aux->prox){
			printf ("%s; ", aux->nomeVerticeAdjacente);
		}
		puts("");
	}
}
