#ifndef SASM_INSTRUCTION_H
#define SASM_INSTRUCTION_H

#include <string.h>
#include "Symbol.h"
#include "utils.h"

class Instruction {
	public:
		parseLine(const std::string& line, offset=0, SymTab& table);
	private:
		Instruction();
		size_t _offset;
		Symbol subtrahend_;
		Symbol minuend_;
		Symbol jump_;
};

#endif
