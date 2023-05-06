typedef struct {
	Adj * primeiro;
} Lista;

Lista * inicializaLista();
void insereLista(Lista * adj, char nomeVerticeAdjacente[NUM_CARACTERES_VERTICE]);