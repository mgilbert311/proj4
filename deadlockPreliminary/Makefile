all: RAG.o stack.o deadlock.c
	gcc -Wall -o deadlock deadlock.c RAG.o stack.o

RAG.o: RAG.c RAG.h
	gcc -Wall -c RAG.c

stack.o: stack.c stack.h
	gcc -Wall -c stack.c

clean: 
	rm -f *.o deadlock