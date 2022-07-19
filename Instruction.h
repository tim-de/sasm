#ifndef SASM_INSTRUCTION_H
#define SASM_INSTRUCTION_H

#include <string.h>
#include "Symbol.h"

class Instruction {
	public:
		Instruction(std::string line);
	private:
		size_t offset_;
		Symbol subtrahend_;
		Symbol minuend_;
		Symbol jump_;
};

#endif
