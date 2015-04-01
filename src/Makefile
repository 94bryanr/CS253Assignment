ASSIGNMENT = pa5
CC= g++
CFLAGS= -c -Wall -std=c++98 -pedantic-errors -Wsign-compare
OBJFILES = main.o PGM.o PGMreader.o PGMAreader.o PGMBreader.o PGMwriter.o PGMAwriter.o PGMBwriter.o KeyPoint.o Mapping.o ExitWithError.o Morph.o

PA: $(OBJFILES)
		$(CC) $(OBJFILES) -o $(ASSIGNMENT)

main.o: main.cpp 
		$(CC) $(CFLAGS) main.cpp

PGM.o: PGM.cpp PGM.h
		$(CC) $(CFLAGS) PGM.cpp

PGMwriter.o: PGMwriter.cpp PGMwriter.h
		$(CC) $(CFLAGS) PGMwriter.cpp

PGMAwriter.o: PGMAwriter.cpp PGMAwriter.h
		$(CC) $(CFLAGS) PGMAwriter.cpp

PGMBwriter.o: PGMBwriter.cpp PGMBwriter.h
		$(CC) $(CFLAGS) PGMBwriter.cpp

PGMreader.o: PGMreader.cpp PGMreader.h 
		$(CC) $(CFLAGS) PGMreader.cpp 
	
PGMAreader.o: PGMAreader.cpp PGMAreader.h
		$(CC) $(CFLAGS) PGMAreader.cpp
	
PGMBreader.o: PGMBreader.cpp PGMBreader.h
		$(CC) $(CFLAGS) PGMBreader.cpp

KeyPoint.o: KeyPoint.cpp KeyPoint.h
		$(CC) $(CFLAGS) KeyPoint.cpp

Mapping.o: Mapping.cpp Mapping.h
		$(CC) $(CFLAGS) Mapping.cpp

ExitWithError.o: ExitWithError.cpp ExitWithError.h
		$(CC) $(CFLAGS) ExitWithError.cpp
	
Morph.o: Morph.cpp Morph.h
		$(CC) $(CFLAGS) Morph.cpp

tar: 
		tar -cf $(ASSIGNMENT).tar *.h *.cpp Makefile

clean:
		rm *.o *.pgm $(ASSIGNMENT) $(ASSIGNMENT).tar
