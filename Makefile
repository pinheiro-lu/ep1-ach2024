######################################################################
# @author      : luan (luan@$HOSTNAME)
# @file        : Makefile
# @created     : sábado mai 06, 2023 16:25:47 -03
######################################################################

IDIR =./include 
CC=gcc
CFLAGS=-I$(IDIR) -g

ODIR=.

LIBS=

SOURCES = main.c dfs/dfs.c entrada-saida/entrada-saida.c grafo/grafo.c kosaraju/kosaraju.c lista/lista.c ordenacao/ordenacao.c hash/hash.c aleatorio/aleatorio.c
_OBJ = main.o grafo.o dfs.o entrada-saida.o kosaraju.o lista.o ordenacao.o hash.o aleatorio.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

dfs.o: dfs/dfs.c
	$(CC) -c -o $@ $< $(CFLAGS)

aleatorio.o: aleatorio/aleatorio.c
	$(CC) -c -o $@ $< $(CFLAGS)

hash.o: hash/hash.c
	$(CC) -c -o $@ $< $(CFLAGS)

lista.o: lista/lista.c
	$(CC) -c -o $@ $< $(CFLAGS)

entrada-saida.o: entrada-saida/entrada-saida.c
	$(CC) -c -o $@ $< $(CFLAGS)

kosaraju.o: kosaraju/kosaraju.c
	$(CC) -c -o $@ $< $(CFLAGS)

grafo.o: grafo/grafo.c
	$(CC) -c -o $@ $< $(CFLAGS)

ordenacao.o: ordenacao/ordenacao.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o

