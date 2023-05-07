#include <stdio.h>

#include "estruturas.h"
#include "lista/lista.h"
#include "grafo/grafo.h"
#include "dfs/dfs.h"
#include "entrada-saida/entrada-saida.h"

#include "kosaraju/kosaraju.h"

#include "ordenacao/ordenacao.h"

// Função criada pelo grupo
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

	Grafo * sccs = (algoritmo == 1 ? SCCs1(grafo) : SCCs2(grafo));

	imprimeSaida(sccs);

    return 0;
}
