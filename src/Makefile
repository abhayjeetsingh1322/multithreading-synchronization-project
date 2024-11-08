# Makefile for Lab 3

# Targets all
all: lab3.zip createThreads parallel1 parallel2 parallel3

# Target .zip file for submission
lab3.zip: Makefile createThreads.c parallel1.c parallel2.c parallel3.c
	zip lab3.zip Makefile createThreads.c parallel1.c parallel2.c parallel3.c

# Target executables for each program
createThreads: createThreads.c
	gcc -std=c99 -pthread -o createThreads createThreads.c

parallel1: parallel1.c
	gcc -std=c99 -pthread -o parallel1 parallel1.c

parallel2: parallel2.c
	gcc -std=c99 -pthread -o parallel2 parallel2.c

parallel3: parallel3.c
	gcc -std=c99 -pthread -o parallel3 parallel3.c

# Target to remove all files produced by Makefile
clean:
	rm -rf lab3.zip createThreads parallel1 parallel2 parallel3
