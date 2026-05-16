all: compilar

compilar: pilha.o main.o comodos.o
	gcc pilha.o main.o comodos.o -o compilado

run: all 
	./compilado

clean:
	rm -rf *.o compilado

pilha.o: pilha.c pilha.h
	gcc -c pilha.c -Wall -Werror -Wextra

main.o: main.c pilha.h
	gcc -c main.c -Wall -Werror -Wextra

comodos.o: comodos.c comodos.h pilha.h
	gcc -c comodos.c -Wall -Werror -Wextra
