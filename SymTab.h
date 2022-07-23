#ifndef SASM_SYMTAB_H
#define SASM_SYMTAB_H

#include <string>
#include <unordered_map>
#include "Symbol.h"
#include "utils.h"

class SymTab {
	public:
		SymTab();
		int addSymbol(const std::string& name);
		int addSymbol(const std::string& name, size_t offset);
		int addStatic(size_t offset);
		int locateSymbol(const std::string& name, size_t offset);
		Symbol& get(const std::string& name);
		bool contains(const std::string& name);
	private:
		std::unordered_map<std::string, Symbol> _table;
};

#endif
