#ifndef SASM_SYMBOL_H
#define SASM_SYMBOL_H

#include <string>

class Symbol {
	public:
		Symbol(const std::string& name, const size_t offset);
		Symbol(const std::string& name);
		Symbol();
		size_t offset() const;
		int locate(size_t offset);
		bool located();
		const std::string& name() const;
	private:
		size_t _offset;
		bool _located;
		std::string _name;
};

#endif
