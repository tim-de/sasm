#include <string>
#include <iostream>
#include "Symbol.h"

Symbol::Symbol():
	_offset(0),
	_located(false)
{}

// Pattern for when the label definition is encountered before it is used
Symbol::Symbol(const std::string& name, const size_t offset):
	_offset(offset),
	_located(true),
	_name(name)
{}

// Pattern for when the label is used before it has been defined
Symbol::Symbol(const std::string& name):
	_offset(0),
	_located(false),
	_name(name)
{}

Symbol::Symbol(const Symbol& other):
	_offset(other._offset),
	_located(other._located),
	_name(other._name)
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
		std::cerr << "Cannot assign offset " << offset << " to " << _name << std::endl << "Already assigned offset " << _offset << std::endl;
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
