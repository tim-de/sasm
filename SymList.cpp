#include <string>
#include <vector>
#include <iostream>
#include "Symbol.h"
#include "SymTab.h"
#include "utils.h"
#include "SymList.h"

SymList::SymList(const size_t entry, const BitWidth width):
	_entry(entry),
	_bit_width(1 << width)
{}

int SymList::parseLine(const std::string& line, const size_t offset, SymTab& table)
{
	size_t position = 0;
	for (std::string sym : split_str(line, " ", true)) {
		//std::cout << "_" << sym << std::endl;
		if (position == 3) {
			return 0;
		}
		if (std::isdigit(sym.front()) || sym.front() == '-') {
			try {
				size_t offset = str_to_size_t(sym) % (1 << _bit_width);
				std::string name = name_static_symbol(offset);
				if (!table.contains(name)) {
					if (table.addSymbol(name, offset) != 0) {return -1;}
				}
				_list.push_back(&table.get(name));
				//std::cout << "s-" << name << std::endl;
				position ++;
			} catch (const std::exception& err) {
				std::cerr << "Error: Invalid address \"" << sym << "\"" << std::endl;
				std::cerr << "in line \"" << line << "\"" << std::endl;
				std::cerr << err.what() << std::endl;
				return -1;
			}
		}
		
		else if (sym.back() == ':') {
			// This is a label definition
			std::string name = sym.substr(0, sym.length()-1);
			if (table.contains(name)) {
				// Encountering label definition after label has been used
				if (table.locateSymbol(name, offset+position) != 0) {return -2;}
			}
			else {
				// Encountering label definition before label is used
				if (table.addSymbol(name, offset+position) != 0) {return -3;}
			}
		}
		else {
			// This is an operand of an instruction
			if (!table.contains(sym)) {
				// Label is undefined
				//std::cout << "u-" << sym << std::endl;
				if (table.addSymbol(sym) != 0) {return -4;}
			}
			_list.push_back(&table.get(sym));
			position ++;
		}
	}
	if (position == 1) {
		_list.push_back(_list.back());
		position ++;
	}
	if (position == 2) {
		std::string name = name_static_symbol(offset+3);
		//std::cout << "t-" << name << std::endl;
		if (!table.contains(name)) {
			if (table.addSymbol(name, offset+3) != 0) {return -5;}
		}
		_list.push_back(&table.get(name));
	}
	return 0;
}

int SymList::parseFile(const std::vector<std::string>& instructions, SymTab& table)
{
	int linenum = 1;
	size_t offset = _entry;
	for (std::string line : instructions) {
		//std::cerr << "[ " << linenum << ": " << line << " ]"<< std::endl;
		int ret = parseLine(line, offset, table);
		if (ret != 0) {return ret;}
		offset += 3;
		linenum ++;
	}
	return 0;
}

void SymList::printOut()
{
	int lnum = 0;
	for (Symbol* sym : _list) {
		if (lnum == 3) {
			std::cout << std::endl;
			lnum = 0;
		}
		std::cout << sym->offset() << "\t";
		lnum ++;
	}
	std::cout << std::endl;
}
