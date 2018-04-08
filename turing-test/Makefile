CC=gcc
CFLAGS=-Wall -Werror

.PHONY: default clean

default: bin/turing

bin/turing: bin build/main.o
	$(CC) $(CFLAGS) build/main.o -o bin/turing

build/main.o: build src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf bin build
