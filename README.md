# Ordenador Topológico de Componentes Conectados
Projeto criado como resolução do primeiro exercício-programa de Algoritmos e Estruturas de Dados II (AED II) ministrada pela Prof. Dr. Karina Valdivia Delgado no primeiro semestre de 2023 na EACH-USP.
O programa recebe um grafo direcionado, encontra seus componentes fortemente conectados e devolve-os topologicamente ordenados.
## Compilação
Para compilar o programa, basta rodar um `make` no diretório do projeto.
O arquivo `main` gerado será o executável.
## Interação
Para interagir com o programa, rode-o com `./main`.
Na primeira linha da entrada, escreva o número `n` de vértices do grafo direcionado.
Nas próximas `n` linhas, descreva as adjacências dos vértices na forma `a: b; c;`, indicando que o vértice `a` é adjacente aos vértices `b` e `c`. Se um vértice `b`não tem adjacências, escreva apenas `b:`.
Os vértices são descritos por palavras de até NUM_CARACTERES_VERTICE caracteres. Uma linha pode ter no máximo NUM_CARACTERES_LINHA caracteres. Ambos os valores estão definidos no arquivo estruturas.h.
Na última linha de entrada, escreva a versão (1 ou 2) do algoritmo de Kosaraju que você quer que rode.
## Saída
A primeira linha da saída será dada pela resposta da pergunta: o grafo é fortemente conectado?
A segunda linha dirá quantos componentes conectados (`m`) têm o grafo.
A terceira linha descreverá uma ordenação topológica do grafo dos componentes fortemente conectados.
As próximas `m` linhas descreverão as adjacências dos componentes fortemente conectados.
