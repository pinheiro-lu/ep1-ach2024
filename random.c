Grafo * grafoaleatorio (int V, int A)
{
  double prob = (double) A / (V * (V - 1));
  
  Grafo *G = inicializaGrafo(V);

  for(int i = 0; i < V; i++)
    {
      G->nomeVertice[i] = (char*) malloc(sizeof(char)*V);
      sprintf(G->nomeVertice[i], "%d", i);
    }
  
  srand(time(NULL));
  
  /*int contador = 0;
  while (contador < A) {
  int aleatorio = rand () % V;
  for (int a = 0; a< V; a++){
    if (aleatorio != a){
      insereListaTransposta(G->adj[aleatorio], a, G->nomeVertice[a]);
  }
    }
  contador += contador;
  printf("%i", contador);
}*/
  
  
  for(int a = 0; a < V; a++)
    {
      for(int b = 0; b < V; b++)
        {
          if(a != b)
            {
              if(rand() < prob*(RAND_MAX+1.0))
                {
                  printf ("\n VerticeOrigem %i\n", a);
                  printf ("\n VerticeDestino %i\n", b);
                  Lista* Aresta = (Lista*) malloc(sizeof(Lista)*a);
                  insereListaTransposta(G->adj[a], b, G->nomeVertice[b]);
                }
            }
        }
    }   
  return G;
}
