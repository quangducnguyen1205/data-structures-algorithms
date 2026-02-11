CC=clang
CFLAGS=-I include

SRC=src/main.c src/lists/*.c src/trees/*.c
BIN=dsalgo

.PHONY: build run clean

build: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run: build
	./$(BIN)

clean:
	rm -f $(BIN)
