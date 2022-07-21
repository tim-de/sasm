#include <string.h>
#include <unordered_map>
#include "Symbol.h"
#include "Instruction.h"
#include "utils.h"
#include "SymTab.h"

SymTab::SymTab() {}

int SymTab::addSymbol(const std::string& name)
{
	// Ensures that the label does not exist in the table
	if (_table.contains(name)) {
		return -1;
	}
	_table[name] = Symbol(name);
	return 0;
}

int SymTab::addSymbol(const std::string& name, const size_t offset)
{
	if (_table.contains(name)) {
		return -1;
	}
	_table[name] = Symbol(name, offset)
}

int SymTab::locateSymbol(const size_t offset)
{
	// Ensures that the label already exists in the table
	if (!_tablecontains(name)) {
		return -1;
	}
	// Passes the success or failure report from Symbol::locate()
	return _table[name].locate(offset);
}

const Symbol& SymTab::get(const std::string& name) const
{
	return _table[name];
}

bool SymTab::contains(const std::string& name)
{
	return _table.contains(name);
}
