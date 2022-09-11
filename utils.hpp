#ifndef SASM_UTILS_H
#define SASM_UTILS_H

#include <string>
#include <cstring>
#include <vector>
#include <fstream>

namespace Width {
	enum Enum {
		b8=0,
		b16,
		b32
	};
}

std::vector<std::string> split_str(const std::string& s, const char* delimiter, const bool ignore_empty=false);

std::vector<std::string> get_instructions(const std::string& infile);

// A wrapper to handle the two exceptions possible to be thrown
// by the std::stoi function
int try_stoi(const std::string& numstr, size_t* idx = 0, int base = 10);

size_t str_to_size_t(const std::string num_s);

const std::string name_static_symbol(const size_t offset);

const int lazy_log_2(int num);

const Width::Enum itowidth(int num);

void putchars(const size_t value, Width::Enum width);

#endif
