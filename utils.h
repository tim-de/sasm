#ifndef SASM_UTILS_H
#define SASM_UTILS_H

#include <string>
#include <cstring>
#include <vector>
#include <fstream>

enum BitWidth { b8=3, b16, b32 };

std::vector<std::string> split_str(const std::string& s, const char* delimiter, const bool ignore_empty=false);

std::vector<std::string> get_instructions(const std::string& infile);

size_t str_to_size_t(const std::string num_s);

const std::string name_static_symbol(const size_t offset);

#endif
