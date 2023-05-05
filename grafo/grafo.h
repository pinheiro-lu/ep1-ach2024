typedef struct {
	char ** nomeVertice;
	Lista ** adj;
	int V;
	int A;
	int * cor;
	int * d;
	int * f;
	int * pai;
} Grafo;

Grafo * inicializaGrafo(int n);
int encontraVertice(Grafo * grafo, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]);
void ajustaVerticesAdjacentes(Grafo * grafo);
void insereListaTransposta(Lista * listaArestas, int indiceAdjacente, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]);
Lista ** tranposicaoArestas(Grafo * grafo);
int contaArvores(Grafo * grafo);