#include <string.h>
#include "Symbol.h"
#include "Instruction.h"

Instruction::Instruction(std::string line) {
	offset_ = 0;
	Symbol subtrahend_(std::string("none"));
	Symbol minuend_(std::string("none"));
	Symbol jump_(std::string("none"));

}
