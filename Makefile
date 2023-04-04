all: main.o headers.o sources.o
	gcc -o main main.o headers.o sources.o

main.o : main.c
	gcc -c main.c

headers.o : headers/*
	gcc -c 