CC = gcc
CFLAGS = -I../lista_modul
LDFLAGS = -L../lista_biblioteka -llista_powiazana

BIN = program
SRC = main.c
OBJ = main.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

main.o: main.c ../lista_modul/lista_powiazana.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(OBJ) $(BIN)
