#include <string>
#include "Symbol.h"

Symbol::Symbol(size_t offset, std::string name) {
	offset_ = offset;
	name_ = name;
}

Symbol::Symbol(std::string name) {
	offset_ = -1;
	name_ = name;
}

size_t Symbol::offset() {
	return offset_;
}

std::string Symbol::name() {
	return name_;
}
