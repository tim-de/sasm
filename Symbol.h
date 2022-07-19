#ifndef SASM_SYMBOL_H
#define SASM_SYMBOL_H

#include <string>

class Symbol {
	public:
		Symbol(size_t offset, std::string name);
		Symbol(std::string name);
		size_t offset();
		std::string name();
	private:
		size_t offset_;
		std::string name_;
};

#endif
