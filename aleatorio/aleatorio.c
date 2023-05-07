#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../estruturas.h"
#include "../lista/lista.h"
#include "../grafo/grafo.h"

#include "aleatorio.h"

// Função inspirada no "Outro construtor de grafos aleatórios" de https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/random.html
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
