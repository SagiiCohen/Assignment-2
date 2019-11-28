# -*- Makefile -*-
all: myLibrary.so maind

maind: main.o myLibrary.so
	gcc -Wall -o maind main.o ./myLibrary.so
myLibd: myLibrary.so

main.o: main.c myBank.h
	gcc -Wall -c main.c
myBank.o: myBank.c myBank.h
	gcc -Wall -fPIC -c myBank.c
myLibrary.so: myBank.o
	gcc -shared -o myLibrary.so myBank.o
.PHONY: clean all myLibd

clean: 
	rm -f *.o *.so maind 
