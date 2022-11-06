#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <utility>
#include "Symbol.hpp"
#include "SymTab.hpp"
#include "utils.hpp"
#include "SymList.hpp"

SymList::SymList(const size_t entry, Width::Enum width):
	_entry(entry),
	_width(width)
{}

int SymList::parseLine(std::string& line, const size_t offset, SymTab& table)
{
	size_t position = 0;
	bool dataline = line.front() == '.';
	if (dataline) {
		line = line.substr(1);
	}
	for (std::string sym : split_str(line, " ", true)) {
		//std::cout << "_" << sym << std::endl;
		if (position == 3) {
			return 0;
		}
		if (std::isdigit(sym.front()) || sym.front() == '-') {
			try {
				size_t offset = str_to_size_t(sym);
				std::string name = name_static_symbol(offset);
				if (!table.contains(name)) {
					if (table.addSymbol(name, offset) != 0) {return -1;}                      
				}
				_list.push_back(std::make_pair(&table.get(name), 0));
				//std::cout << "s-" << name << std::endl;
				position ++;
			} catch (const std::exception& err) {
				std::cerr << "Error: Invalid address \"" << sym << "\" ";
				std::cerr << "in line \"" << line << "\" :" << std::endl;
				std::cerr << err.what() << std::endl;
				return -1;
			}
		}
		
		else if (sym.back() == ':') {
			// This is a label definition
			std::string name = sym.substr(0, sym.length()-1);
			if (table.contains(name)) {
				// Encountering label definition after label has been used
				if (table.locateSymbol(name, offset + (position << _width)) != 0) {return -2;}
			}
			else {
				// Encountering label definition before label is used
				if (table.addSymbol(name, offset + (position << _width)) != 0) {return -3;}
			}
		}
		else {

			// This is an operand of an instruction
			int increment = 0;
			// This section handles operands of the form label+/-offset
			bool minus = false;
			std::vector<std::string> split = split_str(sym, "+", true);
			if (split.size() <= 1) {
				split = split_str(sym, "-", true);
				minus = true;
			}
			if (split.size() > 1) {
				sym = split[0];
				increment = (minus) ? - try_stoi(split[1]) : try_stoi(split[1]);
				//std::cerr << sym << " " << increment << std::endl;
			}

			if (!table.contains(sym)) {
				// Label is undefined
				//std::cout << "u-" << sym << std::endl;
				if (table.addSymbol(sym) != 0) {return -4;}
			}
			_list.push_back(std::make_pair(&table.get(sym), increment));
			position ++;
		}
	}

	if (position == 1 && !dataline) {
		_list.push_back(_list.back());
		position ++;
	}
	if (position == 2 && !dataline) {
		std::string name = name_static_symbol(offset+3);
		//std::cout << "t-" << name << std::endl;
		if (!table.contains(name)) {
			if (table.addSymbol(name, offset+(3 << _width)) != 0) {return -5;}
		}
		_list.push_back(std::make_pair(&table.get(name), 0));
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
		offset += 3 << _width;
		linenum ++;
	}
	return 0;
}

void SymList::printOut() const
{
	int lnum = 0;
	std::cout << std::setfill('0');
	for (unsigned i = 0; i < _list.size(); i++) {
		Symbol* sym = _list[i].first;
		int increment = _list[i].second;
		if (lnum == 3) {
			std::cout << std::endl;
			lnum = 0;
		}
		uint32_t mask;
		switch (_width) {
			case Width::b8:
				mask = 0xff;
				break;
			case Width::b16:
				mask = 0xffff;
				break;
			case Width::b32:
				mask = 0xffffffff;
				break;
		}
		std::cout << "0x" << std::noshowbase << std::hex << std::setw(2<<_width) << ((sym->offset() + increment) & mask) << " ";
		lnum ++;
	}
	std::cout << std::endl;
}

void SymList::binaryOut(bool loader) const
{
	if (loader) {
		putchars(_list.size() << _width, _width);
	}
	for (unsigned i = 0; i < _list.size(); i++) {
		Symbol* bsym = _list[i].first;
		int increment = _list[i].second;
		putchars(bsym->offset() + increment, _width);
	}
}
