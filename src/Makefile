CC=g++
CFLAGS=-c -Wall

PA: main.o PGM.o PGMreader.o PGMscale.o
	$(CC) main.o PGMreader.o PGM.o PGMscale.o -o PA2

main.o: main.cpp PGMreader.h PGM.h PGMscale.h
	$(CC) $(CFLAGS) main.cpp

PGM.o: PGM.cpp PGM.h
	$(CC) $(CFLAGS) PGM.cpp

PGMreader.o: PGMreader.cpp PGMreader.h
	$(CC) $(CFLAGS) PGMreader.cpp

PGMscale.o: PGMscale.cpp PGMscale.h
	$(CC) $(CFLAGS) PGMscale.cpp
