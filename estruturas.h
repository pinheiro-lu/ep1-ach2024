#define NUM_CARACTERES_LINHA 1000
#define NUM_CARACTERES_VERTICE NUM_CARACTERES_LINHA

typedef struct __adj__ {
	struct __adj__ * prox;
	char * nomeVerticeAdjacente;
	int vertice;
} Adj;