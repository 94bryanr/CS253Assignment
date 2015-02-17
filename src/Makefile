INC_WRITER = writer
INC_READER = reader
CC=g++
CFLAGS=-c -Wall -std=c++98 -pedantic-errors -I $(INC_WRITER) -I $(INC_READER)

PA: main.o PGM.o PGMreader.o PGMAreader.o PGMBreader.o PGMscale.o PGMwriter.o
		$(CC) main.o PGMreader.o PGMAreader.o PGMBreader.o PGM.o PGMscale.o PGMwriter.o -o pa2

main.o: main.cpp $(INC_READER)/PGMreader.h PGM.h PGMscale.h $(INC_WRITER)/PGMwriter.h
		$(CC) $(CFLAGS) main.cpp

PGM.o: PGM.cpp PGM.h
		$(CC) $(CFLAGS) PGM.cpp

PGMscale.o: PGMscale.cpp PGMscale.h
		$(CC) $(CFLAGS) PGMscale.cpp

PGMwriter.o: $(INC_WRITER)/PGMwriter.cpp $(INC_WRITER)/PGMwriter.h
		$(CC) $(CFLAGS) $(INC_WRITER)/PGMwriter.cpp

PGMreader.o: $(INC_READER)/PGMreader.cpp $(INC_READER)/PGMreader.h 
		$(CC) $(CFLAGS) $(INC_READER)/PGMreader.cpp 
	
PGMAreader.o: $(INC_READER)/PGMAreader.cpp $(INC_READER)/PGMAreader.h
		$(CC) $(CFLAGS)  $(INC_READER)/PGMAreader.cpp
	
PGMBreader.o: $(INC_READER)/PGMBreader.cpp $(INC_READER)/PGMBreader.h
		$(CC) $(CFLAGS)  $(INC_READER)/PGMBreader.cpp
