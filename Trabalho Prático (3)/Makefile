CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp3
TMPOUT=tp3.testresult

.PHONY: all build test clean

all: build test clean

build:
	$(CC) $(CFLAGS) -c src/list.cpp -o list.o
	$(CC) $(CFLAGS) -c src/text.cpp -o text.o
	$(CC) $(CFLAGS) -c src/hash.cpp -o hash.o
	$(CC) $(CFLAGS) -c src/minheap.cpp -o minheap.o
	$(CC) $(CFLAGS) src/main.cpp list.o text.o hash.o minheap.o -o $(EXEC)

test: $(build)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf list.o text.o hash.o minheap.o
