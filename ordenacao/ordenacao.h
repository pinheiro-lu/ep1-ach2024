typedef struct {
	int f;
	int indice;
} Pair;

int compare(const void *l, const void *r);
void ordenacaoTopologica (Grafo * grafo);