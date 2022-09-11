#ifndef SASM_SYMLIST_H
#define SASM_SYMLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Symbol.hpp"
#include "SymTab.hpp"
#include "utils.hpp"

class SymList {
	// SymList is the listing of the program, formed of pointers to
	// Symbol objects that can be resolved to a list of addresses
	// once all Symbols have been successfully located.
	// It is used to perform the actual assembly
	public:
		SymList(const size_t entry=0, Width::Enum width=Width::b8);
		int parseLine(std::string& line, const size_t offset, SymTab& table);
		int parseFile(const std::vector<std::string>& instructions, SymTab& table);
		void printOut() const;
		void binaryOut(bool loader) const;
	private:
		size_t _entry;
		Width::Enum _width;
		std::vector< std::pair< Symbol*, int32_t > > _list;
};

#endif
