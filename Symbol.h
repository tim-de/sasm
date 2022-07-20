#ifndef SASM_SYMBOL_H
#define SASM_SYMBOL_H

#include <string>

class Symbol {
	public:
		Symbol(size_t offset, const std::string& name);
		Symbol(const std::string& name);
		size_t offset() const;
		const std::string& name() const;
	private:
		size_t offset_;
		std::string name_;
};

#endif
