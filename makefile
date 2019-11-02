ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o linkedlist.o musiclibrary.o
	$(CC) -o program main.o linkedlist.o musiclibrary.o

main.o: main.c musiclibrary.h linkedlist.h
	$(CC) -c main.c

musiclibrary.o: musiclibrary.c musiclibrary.h linkedlist.h
	$(CC) -c musiclibrary.c 

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c


run:
	./program

memcheck:
	valgrind --leak-check=yes ./program

clean:
	rm *.o
	rm *~