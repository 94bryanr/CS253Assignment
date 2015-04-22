ASSIGNMENT = pa6
ASSIGNMENTCAP = PA6
CC= g++
CFLAGS= -c -Wall -std=c++98 -pedantic-errors -Wsign-compare
OBJFILES = main.o PGM.o PGMreader.o PGMAreader.o PGMBreader.o PGMwriter.o PGMAwriter.o PGMBwriter.o KeyPoint.o Mapping.o ExitWithError.o Morph.o ExtendedKeyPoint.o PGMshader.o Coordinate.o

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
	
PGMshader.o: PGMshader.cpp PGMshader.h
		$(CC) $(CFLAGS) PGMshader.cpp

KeyPoint.o: KeyPoint.cpp KeyPoint.h
		$(CC) $(CFLAGS) KeyPoint.cpp

ExtendedKeyPoint.o: ExtendedKeyPoint.cpp ExtendedKeyPoint.h
		$(CC) $(CFLAGS) ExtendedKeyPoint.cpp

Mapping.o: Mapping.cpp Mapping.h
		$(CC) $(CFLAGS) Mapping.cpp

ExitWithError.o: ExitWithError.cpp ExitWithError.h
		$(CC) $(CFLAGS) ExitWithError.cpp
	
Morph.o: Morph.cpp Morph.h
		$(CC) $(CFLAGS) Morph.cpp

Coordinate.o: Coordinate.cpp Coordinate.h
		$(CC) $(CFLAGS) Coordinate.cpp

tar: 
		tar -cf $(ASSIGNMENTCAP).tar *.h *.cpp Makefile

clean:
		rm *.o *.pgm $(ASSIGNMENT) $(ASSIGNMENTCAP).tar
