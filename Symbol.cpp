#include <string>
#include "Symbol.h"

Symbol::Symbol(size_t offset, const std::string& name)
:	offset_(offset),
	name_(name)
{}

Symbol::Symbol(const std::string& name)
:	offset_(0),
	name_(name)
{}

/*Symbol::Symbol() {
	offset_ = 0;
	name_ = "";
}*/

size_t Symbol::offset() const {
	return offset_;
}

const std::string& Symbol::name() const {
	return name_;
}
