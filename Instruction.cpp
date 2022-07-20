#include <string.h>
#include "Instruction.h"
#include "Symbol.h"

Instruction::Instruction(const std::string& line) 
:	offset_(0),
	subtrahend_("none"),
	minuend_("none"),
	jump_("none")
{}

