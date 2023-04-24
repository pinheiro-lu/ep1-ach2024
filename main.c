#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARACTERES_LINHA 1000
#define NUM_CARACTERES_VERTICE NUM_CARACTERES_LINHA

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
		
//		printf("cheguei aqui\n");
		scanf("\n%[^\n]", linha);

//		printf("%s\n", linha);
		int offset = 0, numCaracteresLidos;

		sscanf(linha, "%[^:]:%n", nomeVertice[i], &numCaracteresLidos);
//		printf("%s\n", nomeVertice[i]);

		offset += numCaracteresLidos;
		
		char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE];

		while(sscanf(linha + offset, " %[^;]%n", nomeVerticeAdjacente, &numCaracteresLidos) == 1) {
			insere(adj, i, nomeVerticeAdjacente);
			offset += numCaracteresLidos;
			if (linha[offset] == ';') offset++; 
//			printf("%s %d", nomeVerticeAdjacente, numCaracteresLidos);
		}
//		puts("");

		printf("%s: ", nomeVertice[i]);
		Adj* aux = adj[i]->primeiro;
		while (aux) {
			printf("%s; ", aux->nomeVertice);
			aux = aux->prox;
		}
		puts("");
	}

    return 0;
}

