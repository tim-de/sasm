#include <string>
#include <unordered_map>
#include <iostream>
#include "Symbol.h"
#include "utils.h"
#include "SymTab.h"

SymTab::SymTab() {}

int SymTab::addSymbol(const std::string& name)
{
	// Ensures that the label does not exist in the table
	if (_table.count(name) > 0) {
		return -1;
	}
	_table.try_emplace(name, name);
	return 0;
}

int SymTab::addSymbol(const std::string& name, size_t offset)
{
	if (_table.count(name) > 0) {
		return -1;
	}
	_table.try_emplace(name, name, offset);
	return 0;
}

int SymTab::locateSymbol(const std::string& name, size_t offset)
{
	// Ensures that the label already exists in the table
	if (!contains(name)) {
		std::cerr << "Label \"" << name << "\" does not exist in table" << std::endl;
		return -1;
	}
	// Passes the success or failure report from Symbol::locate()
	return _table.at(name).locate(offset);
}

Symbol& SymTab::get(const std::string& name)
{
	return _table.at(name);
}

bool SymTab::contains(const std::string& name)
{
	return (_table.count(name) != 0);
}
