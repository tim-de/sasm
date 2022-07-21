CC = g++

CFLAGS = -Wall -g

default: sasm 

sasm: sasm.o Symbol.o Instruction.o utils.o 
	$(CC) $(CFLAGS) -o sasm sasm.o Symbol.o Instruction.o utils.o

sasm.o: sasm.cpp Symbol.h Instruction.h
	$(CC) $(CFLAGS) -c sasm.cpp Symbol.h Instruction.h

Symbol.o: Symbol.cpp
	$(CC) $(CFLAGS) -c Symbol.cpp

Instruction.o: Instruction.cpp Symbol.h utils.h
	$(CC) $(CFLAGS) -c Instruction.cpp Symbol.h utils.h

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

clean:
	$(RM) sasm *.o *~ *.gch
