#ifndef SASM_SYMLIST_H
#define SASM_SYMLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Symbol.h"
#include "SymTab.h"
#include "utils.h"

class SymList {
	// SymList is the listing of the program, formed of pointers to
	// Symbol objects that can be resolved to a list of addresses
	// once all Symbols have been successfully located.
	// It is used to perform the actual assembly
	public:
		SymList(const size_t entry=0, const BitWidth width=b8);
		int parseLine(const std::string& line, const size_t offset, SymTab& table);
		int parseFile(const std::vector<std::string>& instructions, SymTab& table);
		void printOut();
	private:
		size_t _entry;
		uint8_t _bit_width;
		std::vector<Symbol*> _list;
};

#endif
