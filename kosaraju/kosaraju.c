#include <string.h>
#include <stdlib.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"
#include "../dfs/dfs.h"
#include "../ordenacao/ordenacao.h"

#include "kosaraju.h"

// Funções criadas pelo grupo. Lógica adaptada do material de AED II

Grafo * kosaraju (Grafo * grafo){
	Grafo * sccs = inicializaGrafo(contaArvores(grafo));

	for (int i = 0; i < sccs->V; i++) {
		sccs->nomeVertice[i] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
		sccs->adj[i] = inicializaLista();
	}

	int * localVertices = (int *) malloc(sizeof(int) * grafo->V);

	for (int i = 0; i < grafo->V; i++) {
		localVertices[i] = -1;
	}

	int livre = 0;

	for (int i = 0; i < grafo->V; i++) {
		if (localVertices[grafo->pai[i]] == -1) {
			localVertices[grafo->pai[i]] = livre++;
		}
		strncat(sccs->nomeVertice[localVertices[grafo->pai[i]]], grafo->nomeVertice[i], NUM_CARACTERES_VERTICE);
	}


	for (int i = 0; i <grafo->V; i++){
		Adj * aux = grafo->adj[i]->primeiro;
			while (aux){
				int j = aux->vertice;
				if (grafo->pai[i] != grafo->pai[j]){
					for (Adj * auxiliar = sccs->adj[localVertices[grafo->pai[i]]]->primeiro; auxiliar; auxiliar = auxiliar->prox){
						if (auxiliar->vertice == localVertices[grafo->pai[j]]) //condição de dois iguais
							goto oi;
					}
					insereLista(sccs->adj[localVertices[grafo->pai[i]]], localVertices[grafo->pai[j]], sccs->nomeVertice[localVertices[grafo->pai[j]]]);		
				}
			oi:
			aux = aux->prox;
		}
	}

	DFS(sccs, sccs->adj);
	ordenacaoTopologica(sccs);


	return sccs;

}
Grafo * SCCs1(Grafo * grafo) {
	DFS(grafo, tranposicaoArestas(grafo));
	ordenacaoTopologica(grafo);
	DFS(grafo, grafo->adj);

	return kosaraju (grafo);
}

Grafo * SCCs2 (Grafo * grafo){
	DFS(grafo, grafo->adj);
	ordenacaoTopologica(grafo);
	DFS(grafo, tranposicaoArestas(grafo));
	
	return kosaraju(grafo);

}
