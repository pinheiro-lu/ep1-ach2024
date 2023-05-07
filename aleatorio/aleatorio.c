#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../estruturas.h"
#include "../grafo/grafo.h"

#include "aleatorio.h"

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
  srand(time(NULL)); 
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
}
