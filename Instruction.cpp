#include <string.h>
#include "Instruction.h"
#include "Symbol.h"
#include "utils.h"

Instruction::parseLine(const std::string& line, const size_t offset, SymTab& table) 
{
	_offset = offset;
	size_t position = 0;
	for (std::string sym : split_str(line, " ", true)) {
		if (sym.back() == ':') {
		}
	}

	subtrahend_.name(inst[0]);
	minuend_.name(inst[1]);
	jump_.name(inst[2]);
}

