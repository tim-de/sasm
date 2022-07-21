#ifndef SASM_UTILS_H
#define SASM_UTILS_H

#include <string>
#include <cstring>
#include <vector>
#include <fstream>

std::vector<std::string> split_str(const std::string& s, const char* delimiter, const bool ignore_empty=false);

std::vector<std::string> get_instructions(const std::string& infile);

#endif
