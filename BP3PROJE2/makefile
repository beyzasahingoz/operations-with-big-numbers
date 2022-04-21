CC=gcc

CFLAGS=-c	-Wall

all:makeDeneme

makeDeneme:	main.o	islemler.o

	$(CC)	main.o	islemler.o	-o	makeDeneme
main.o:	main.c
	$(CC)	$(CFLAGS)	main.c
islemler.o:	islemler.c	islemler.h
	$(CC)	$(CFLAGS)	islemler.c
clean:
	del	*.o	makeDeneme.exe