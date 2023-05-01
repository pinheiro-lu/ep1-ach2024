#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARACTERES_LINHA 1000
#define NUM_CARACTERES_VERTICE NUM_CARACTERES_LINHA
#define MAX_NUM_VERTICES 1000
#define BRANCO 1
#define CINZA 2
#define PRETO 3

int cor [MAX_NUM_VERTICES];
int d[MAX_NUM_VERTICES], f[MAX_NUM_VERTICES];
int pai[MAX_NUM_VERTICES];
int isAdjacente[MAX_NUM_VERTICES][MAX_NUM_VERTICES];

typedef struct __adj__ {
	struct __adj__ * prox;
	char nomeVertice[NUM_CARACTERES_VERTICE];
} Adj;

typedef struct {
	Adj * primeiro;
} Lista;

void insere(Lista ** adj, int vertice, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]) {
	Adj * aux = adj[vertice]->primeiro;

	adj[vertice]->primeiro = (Adj *) malloc(sizeof(Adj));
	adj[vertice]->primeiro->prox = aux;
	strcpy(adj[vertice]->primeiro->nomeVertice, nomeVerticeAdjacente);
}

void DFSvisit (Lista ** adj, int u, int numVertices){
	int contador = 0;
	cor[u] = CINZA;
	contador += contador;
	d[u] = contador;
	for (int v = 0; v< numVertices; v++){
		if (isAdjacente[u][v] == 1)
			if (cor[v] == BRANCO){
				pai[v] = u;
				DFSvisit (adj, v, numVertices);
		}	
	}
	cor[u] = PRETO;
	contador += contador;
	f[u] = contador;
} 


int main()
{
	int numVertices;

	scanf("%d", &numVertices);

	char ** nomeVertice = (char **) malloc(sizeof(char *) * numVertices);
	Lista ** adj = (Lista **) malloc(sizeof(Lista *) * numVertices);
	
	for (int i = 0; i < numVertices; i++) {
		nomeVertice[i] = (char *) malloc(sizeof(char) * NUM_CARACTERES_VERTICE);
		adj[i] = (Lista *) malloc(sizeof(Lista));
		adj[i]->primeiro = NULL;

		char linha[NUM_CARACTERES_LINHA];
		
		scanf("\n%[^\n]", linha);

		int offset = 0, numCaracteresLidos;

		sscanf(linha, "%[^:]:%n", nomeVertice[i], &numCaracteresLidos);

		offset += numCaracteresLidos;
		
		char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE];

		while(sscanf(linha + offset, " %[^;];%n", nomeVerticeAdjacente, &numCaracteresLidos) == 1) {
			insere(adj, i, nomeVerticeAdjacente);
			for (int x = 0; x<numVertices; x++)
				if (strcmp(nomeVerticeAdjacente, nomeVertice[x]) == 0)
					isAdjacente[i][x] = 1;
			offset += numCaracteresLidos;
		}

		printf("%s: ", nomeVertice[i]);
		Adj* aux = adj[i]->primeiro;
		while (aux) {
			printf("%s; ", aux->nomeVertice);
			aux = aux->prox;
		}
		puts("");
	}

	int algoritmo;
	scanf("%d", &algoritmo);

    return 0;
}
