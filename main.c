#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARACTERES_LINHA 1000
#define NUM_CARACTERES_VERTICE NUM_CARACTERES_LINHA

typedef struct __adj__ {
	struct __adj__ * prox;
	char * nomeVerticeAdjacente;
	int vertice;
} Adj;

typedef struct {
	Adj * primeiro;
} Lista;

typedef struct {
	char ** nomeVertice;
	Lista ** adj;
	int V;
	int A;
} Grafo;

Lista * inicializaLista() {
	Lista * adj = (Lista *) malloc(sizeof(Lista));
	adj->primeiro = NULL;

	return adj;
}

int encontraVertice(Grafo * grafo, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	for (int i = 0 ; i < grafo->V; i++) {
		if (!strcmp(grafo->nomeVertice[i], nomeVerticeAdjacente)) {
			return i;
		}
	}
	return -1;
}

void insereLista(Grafo * grafo, int vertice, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	Adj * novo = (Adj *) malloc(sizeof(Adj));
	novo->nomeVerticeAdjacente = (char *) malloc(sizeof(char)* NUM_CARACTERES_VERTICE);
	strcpy(novo->nomeVerticeAdjacente, nomeVerticeAdjacente);
	novo->prox = grafo->adj[vertice]->primeiro;
	grafo->adj[vertice]->primeiro = novo;
	grafo->A++;
}

void lerLinhaVertice (char linha[NUM_CARACTERES_LINHA], Grafo * grafo, int vertice) {
	int offset, numCaracteresLidos;

	grafo->nomeVertice[vertice] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
	grafo->adj[vertice] = inicializaLista();

	sscanf(linha, "%[^:]:%n", grafo->nomeVertice[vertice], &numCaracteresLidos);

	offset = numCaracteresLidos;
		
	char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE];

	while(sscanf(linha + offset, " %[^;];%n", nomeVerticeAdjacente, &numCaracteresLidos) == 1) {
		insereLista(grafo, vertice, nomeVerticeAdjacente);
		offset += numCaracteresLidos;
	}
}

Grafo * inicializaGrafo(int n) {
	Grafo * grafo = (Grafo *) malloc(sizeof(Grafo));

	grafo->nomeVertice = (char **) malloc(sizeof(char *) * n);
	grafo->adj = (Lista **) malloc(sizeof(Lista *) * n);
	grafo->A = 0;
	grafo->V = n;

	return grafo;
}

void ajustaVerticesAdjacentes(Grafo * grafo) {
	for (int i = 0; i < grafo->V; i++) {
		Adj * aux = grafo->adj[i]->primeiro;

		while (aux) {
			aux->vertice = encontraVertice(grafo, aux->nomeVerticeAdjacente);
			aux = aux->prox;
		}

	}
}

int main()
{
	int numVertices;

	scanf("%d", &numVertices);

	Grafo * grafo = inicializaGrafo(numVertices);

	for (int i = 0; i < numVertices; i++) {
		char linha[NUM_CARACTERES_LINHA];
		
		scanf("\n%[^\n]", linha);

		lerLinhaVertice(linha, grafo, i);
	}

	ajustaVerticesAdjacentes(grafo);

	int algoritmo;
	scanf("%d", &algoritmo);

    return 0;
}