#ifndef SASM_SYMLIST_H
#define SASM_SYMLIST_H

#include <string>
#include <vector>
#include "Symbol.h"
#include <SymTab.h>
#include <utils.h>

class SymList {
	public:
		Symlist();
		int parseLine(const std::string& line, const size_t offset, SymTab& table);
	private:
		std::vector<Symbol*> _list;
};

#endif
