CC = g++

CFLAGS = -Wall -g

default: sasm 

sasm: sasm.o Symbol.o SymTab.o SymList.o utils.o 
	$(CC) $(CFLAGS) -o sasm sasm.o Symbol.o SymTab.o SymList.o utils.o

sasm.o: sasm.cpp Symbol.h SymList.h
	$(CC) $(CFLAGS) -c sasm.cpp Symbol.h SymTab.h SymList.h utils.h

Symbol.o: Symbol.cpp
	$(CC) $(CFLAGS) -c Symbol.cpp

SymTab.o: SymTab.cpp Symbol.h utils.h
	$(CC) $(CFLAGS) -c SymTab.cpp Symbol.h utils.h

SymList.o: SymList.cpp Symbol.h SymTab.h utils.h
	$(CC) $(CFLAGS) -c SymList.cpp Symbol.h SymTab.h utils.h

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

clean:
	$(RM) sasm *.o *~ *.gch
