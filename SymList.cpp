#include <string>
#include <vector>
#include "Symbol.h"
#include "SymTab.h"
#include "utils.h"
#include "SymList.h"

SymList::SymList() {}

int SymList::parse_line(const std::string& line, const size_t offset, SymTab& table)
{
	size_t position = 0;
	int code = 0;
	for (std::string sym : split_str(line, " ", true)) {
		if (posision == 3) {
			return 0;
		}
		if (sym.back() == ':') {
			// This is a label definition
			std::string name = substr(name, name.length()-2);
			if (table.contains(name)) {
				// Encountering label definition after label has been used
				code = table.locateSymbol(name, offset+position);
			}
			else {
				// Encountering label definition before label is used
				code = table.addSymbol(name, offset+position);
			}
		}
		else {
			// This is an operand of an instruction
			if (table.contains(name)) {
				// Label is already defined in table
				_list.push_back(&table.get(name))
			}
			else {
				// Label is undefined
				code = table.addSymbol(name);
				_list.push_back(&table.get(name));
			}
		}
	}
}
