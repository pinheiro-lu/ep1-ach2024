#define NUM_CARACTERES_LINHA 1000
#define NUM_CARACTERES_VERTICE NUM_CARACTERES_LINHA

typedef struct __adj__ {
	struct __adj__ * prox;
	char * nomeVerticeAdjacente;
	int vertice;
} Adj;

typedef struct {
	Adj * primeiro;
} Lista;

typedef struct __elemento_hash__ {
	char chave[NUM_CARACTERES_VERTICE];
	int indice;
	struct __elemento_hash__ * prox;
} ElementoHash;

typedef struct {
	char ** nomeVertice;
	Lista ** adj;
	int V;
	int A;
	int * cor;
	int * d;
	int * f;
	int * pai;
	ElementoHash * elemento;
} Grafo;

