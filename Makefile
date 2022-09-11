CC = g++

CFLAGS = -Wall -g

default: sasm 

sasm: sasm.o Symbol.o SymTab.o SymList.o utils.o 
	$(CC) $(CFLAGS) -o sasm sasm.o Symbol.o SymTab.o SymList.o utils.o

sasm.o: sasm.cpp Symbol.hpp SymList.hpp
	$(CC) $(CFLAGS) -c sasm.cpp Symbol.hpp SymTab.hpp SymList.hpp utils.hpp

Symbol.o: Symbol.cpp
	$(CC) $(CFLAGS) -c Symbol.cpp

SymTab.o: SymTab.cpp Symbol.hpp utils.hpp
	$(CC) $(CFLAGS) -c SymTab.cpp Symbol.hpp utils.hpp

SymList.o: SymList.cpp Symbol.hpp SymTab.hpp utils.hpp
	$(CC) $(CFLAGS) -c SymList.cpp Symbol.hpp SymTab.hpp utils.hpp

utils.o: utils.cpp
	$(CC) $(CFLAGS) -c utils.cpp

clean:
	$(RM) sasm *.o *~ *.gch
