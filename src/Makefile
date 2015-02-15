CC=g++
CFLAGS=-c -Wall -std=c++98 -pedantic-errors

PA: main.o PGM.o PGMreader.o PGMscale.o PGMwriter.o
		$(CC) main.o PGMreader.o PGM.o PGMscale.o PGMwriter.o -o pa2

main.o: main.cpp PGMreader.h PGM.h PGMscale.h PGMwriter.h
		$(CC) $(CFLAGS) main.cpp

PGM.o: PGM.cpp PGM.h
		$(CC) $(CFLAGS) PGM.cpp

PGMreader.o: PGMreader.cpp PGMreader.h
		$(CC) $(CFLAGS) PGMreader.cpp

PGMscale.o: PGMscale.cpp PGMscale.h
		$(CC) $(CFLAGS) PGMscale.cpp

PGMwriter.o: PGMwriter.cpp PGMwriter.h
		$(CC) $(CFLAGS) PGMwriter.cpp
