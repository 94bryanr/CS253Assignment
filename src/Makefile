ASSIGNMENT = pa4
CC= g++
CFLAGS= -c -Wall -std=c++98 -pedantic-errors 

PA: main.o PGM.o PGMreader.o PGMAreader.o PGMBreader.o PGMscale.o PGMwriter.o PGMAwriter.o PGMBwriter.o PGMframer.o
		$(CC) main.o PGMreader.o PGMAreader.o PGMBreader.o PGM.o PGMscale.o PGMwriter.o PGMAwriter.o PGMBwriter.o PGMframer.o -o $(ASSIGNMENT)

main.o: main.cpp PGMreader.h PGM.h PGMscale.h PGMwriter.h
		$(CC) $(CFLAGS) main.cpp

PGM.o: PGM.cpp PGM.h
		$(CC) $(CFLAGS) PGM.cpp

PGMscale.o: PGMscale.cpp PGMscale.h
		$(CC) $(CFLAGS) PGMscale.cpp

PGMframer.o: PGMframer.cpp PGMframer.h
		$(CC) $(CFLAGS) PGMframer.cpp

PGMwriter.o: PGMwriter.cpp PGMwriter.h
		$(CC) $(CFLAGS) PGMwriter.cpp

PGMAwriter.o: PGMAwriter.cpp PGMAwriter.h
		$(CC) $(CFLAGS) PGMAwriter.cpp

PGMBwriter.o: PGMBwriter.cpp PGMBwriter.h
		$(CC) $(CFLAGS) PGMBwriter.cpp

PGMreader.o: PGMreader.cpp PGMreader.h 
		$(CC) $(CFLAGS) PGMreader.cpp 
	
PGMAreader.o: PGMAreader.cpp PGMAreader.h
		$(CC) $(CFLAGS)  PGMAreader.cpp
	
PGMBreader.o: PGMBreader.cpp PGMBreader.h
		$(CC) $(CFLAGS)  PGMBreader.cpp

tar: 
		tar -cf $(ASSIGNMENT).tar *.h *.cpp reader/ writer/ Makefile

clean:
		rm *.o *.pgm $(ASSIGNMENT) $(ASSIGNMENT).tar
