#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "estruturas.h"
#include "lista/lista.h"
#include "grafo/grafo.h"
#include "dfs/dfs.h"
#include "entrada-saida/entrada-saida.h"
#include "kosaraju/kosaraju.h"
#include "ordenacao/ordenacao.h"
#include "aleatorio/aleatorio.h"

// Função criada pelo grupo
int main(int argc, char *argv[])
{
	Grafo* grafo;
	Grafo* sccs;

	int algoritmo;

	if (argc == 1)
	{
		int numVertices;
		scanf("%d", &numVertices);

		grafo = inicializaGrafo(numVertices);

		for (int i = 0; i < numVertices; i++)
		{
			char linha[NUM_CARACTERES_LINHA];
			scanf("\n%[^\n]", linha);
			lerLinhaVertice(linha, grafo, i);
		}
		ajustaVerticesAdjacentes(grafo);
		scanf("%d", &algoritmo);
	}

	else
	{
		grafo = grafoAleatorio(atoi(argv[1]), atoi(argv[2]));
		algoritmo = atoi(argv[3]);
	}

	sccs = (algoritmo == 1 ? SCCs1(grafo) : SCCs2(grafo));
	imprimeSaida(sccs);

	return 0;
}
