#include <stdio.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "entrada-saida.h"

void lerLinhaVertice (char linha[NUM_CARACTERES_LINHA], Grafo * grafo, int vertice) {
	int offset, numCaracteresLidos;

	grafo->nomeVertice[vertice] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
	grafo->adj[vertice] = inicializaLista();

	sscanf(linha, "%[^:]:%n", grafo->nomeVertice[vertice], &numCaracteresLidos);

	offset = numCaracteresLidos;
		
	char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE];

	while(sscanf(linha + offset, " %[^;];%n", nomeVerticeAdjacente, &numCaracteresLidos) == 1) {
		insereLista(grafo->adj[vertice], nomeVerticeAdjacente);
		grafo->A++;
		offset += numCaracteresLidos;
	}
}

void imprimeSaida (Grafo * sccs){
	printf (sccs->V == 1 ? "\nSim\n" : "\nNão\n");
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
	printf ("\n");
	}
}