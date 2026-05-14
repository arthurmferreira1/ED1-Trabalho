all: compilar

compilar: pilha.o main.o comodos.o
	gcc pilha.o main.o comodos.o -o compilado

run: all 
	.\compilado

clean:
	rm -rf *.o compilado

pilha.o: pilha.c pilha.h
	gcc pilha.c -o pilha.o -Wall -Werror -Wextra

main.o: main.c pilha.h
	gcc main.c -o main.o -Wall -Werror -Wextra

comodos.o: comodos.c pilha.h
	gcc comodos.c -o cômodos.o -Wall -Werror -Wextra
