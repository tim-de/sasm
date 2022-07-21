#ifndef SASM_SYMTAB_H
#define SASM_SYMTAB_H

#include <string.h>
#include <unordered_map>
#include "Symbol.h"
#include "Instruction.h"
#include "utils.h"

class SymTab {
	public:
		SymTab();
		int addSymbol(const std::string& name);
		int addSymbol(const std::string& name, const size_t offset);
		int locateSymbol(const size_t offset);
		const Symbol& get(const std::string& name) const;
		bool contains(const std::string& name);
	private:
		std::unordered_map<std::string, Symbol> _table;
};

#endif
