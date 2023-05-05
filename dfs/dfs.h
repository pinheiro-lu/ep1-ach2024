#define BRANCO 0
#define CINZA 1
#define PRETO 2

int time;

void DFSvisit (Grafo * grafo, Lista ** adj, int u, int pai);
void DFS (Grafo * grafo, Lista ** adj);