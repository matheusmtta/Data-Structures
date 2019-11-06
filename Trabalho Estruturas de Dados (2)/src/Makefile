CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp2
TMPOUT=tp2.testresult

.PHONY: all build test clean

all: build test clean

build:
	$(CC) $(CFLAGS) -c planet.cpp -o planet.o
	$(CC) $(CFLAGS) -c sort.cpp -o sort.o
	$(CC) $(CFLAGS) main.cpp planet.o sort.o -o $(EXEC)

test: $(build)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf planet.o sort.o