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
/*
Grafo * grafoAleatorio (int V, int A)
{
  double prob = (double) A / (V * (V - 1));
  
  Grafo *G = inicializaGrafo(V);

  for(int i = 0; i < V; i++)
    {
      G->nomeVertice[i] = (char*) malloc(sizeof(char)*NUM_CARACTERES_VERTICE);
      G->adj[i] = (Lista *) malloc(sizeof(Lista));
      sprintf(G->nomeVertice[i], "%d", i);
    }
  srand(0); 
  for(int a = 0; a < V; a++)
    {
      for(int b = 0; b < V; b++)
        {
          if(a != b && (rand() < prob*(RAND_MAX+1.0)))
          {
              insereLista(G->adj[a], b, G->nomeVertice[b]);
          }
        }
    }   
  return G;
}*/


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
