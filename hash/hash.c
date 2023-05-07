/**
 * @author      : luan (luan@$HOSTNAME)
 * @file        : hash
 * @created     : sábado mai 06, 2023 19:17:31 -03
 */
#include <stdlib.h>
#include <string.h>

#include "../estruturas.h"
#include "../grafo/grafo.h"

#include "hash.h"

// Funções adaptadas do material de IAA de 2022 ministrada pelo Prof. Dr. Marcos Lordello Chaim

int hash(Grafo * grafo, char chave[NUM_CARACTERES_VERTICE]) {
int somaValCar = 0;
  int i;
 // Soma os valores dos caracteres
  for(i = 0; chave[i] != '\0' && i < 8; ++i)
    somaValCar += chave[i];
  return (somaValCar % grafo->V);
}

void insereHash (Grafo * grafo, char chave[NUM_CARACTERES_VERTICE], int indice) {
	ElementoHash * novo = (ElementoHash *) malloc(sizeof(ElementoHash));
	strcpy(novo->chave, chave);
	novo->indice = indice;
	novo->prox = grafo->elemento[hash(grafo, chave)].prox;
	grafo->elemento[hash(grafo, chave)].prox = novo;
}

int buscaHash (Grafo * grafo, char chave[NUM_CARACTERES_VERTICE]) {
	int i = hash(grafo, chave);
	ElementoHash * list;

	for (list = grafo->elemento[i].prox; list; list = list->prox) {
		if (!strcmp(list->chave, chave)) break;
	}

	return list->indice;
}

