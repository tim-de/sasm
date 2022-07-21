#include <string>
#include "Symbol.h"

// Pattern for when the label definition is encountered before it is used
Symbol::Symbol(const std::string& name, const size_t offset)
:	_offset(offset),
	_located(true),
	_name(name)
{}

// Pattern for when the label is used before it has been defined
Symbol::Symbol(const std::string& name)
:	_offset(0),
	_located(false),
	_name(name)
{}

size_t Symbol::offset() const
{
	return _offset;
}

int Symbol::locate(const size_t offset)
{
	// Ensures that the Symbol instance does not already
	// have an offset assigned
	if (_located) {
		return -1;
	}
	_offset = offset;
	_located = true;
	return 0; 
}

const bool Symbol::located() const
{
	return _located;
}

const std::string& Symbol::name() const
{
	return _name;
}
