CC = g++

CFLAGS = -Wall
DFLAGS = -g

default: sasm 

sasm: sasm.o Symbol.o Instruction.o
	$(CC) $(CFLAGS) -o sasm sasm.o Symbol.o Instruction.o

sasm.o: sasm.cpp Symbol.h Instruction.h
	$(CC) $(CFLAGS) -c sasm.cpp Symbol.h Instruction.h

Symbol.o: Symbol.cpp
	$(CC) $(CFLAGS) -c Symbol.cpp

Instruction.o: Instruction.cpp
	$(CC) $(CFLAGS) -c Instruction.cpp

clean:
	$(RM) sasm *.o *~ *.gch
