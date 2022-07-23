#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include "utils.h"

std::vector<std::string> split_str(const std::string& s, const char* delimiter, const bool ignore_empty)
{
	std::vector<std::string> s_split;

	size_t start = 0, pos = 0;
	size_t d_len = strlen(delimiter);

	// Find next location of delimiter in s
	while ((pos = s.find(delimiter, start)) != std::string::npos) {
		// Ignore empty strings if required
		if ( start != pos || not ignore_empty ) {
			s_split.push_back(s.substr(start, pos-start));
		}
		// Move the search forward in the string
		start = pos + d_len;
	}

	// Pick up the rest of the string after the last instance of delimiter
	// If delimiter at end of string then add empty string or ignore as needed
	if ( start < s.length() || not ignore_empty ) {
		s_split.push_back(s.substr(start, std::string::npos));
	}
	return s_split;
}

std::vector<std::string> get_instructions(const std::string& infile)
{
	std::ifstream readfile(infile);
	std::vector<std::string> instructions;
	std::string fileline;
	while (getline(readfile, fileline)) {
		// Ensures that there are no trailing \r characters
		// missed by getline
		if (!fileline.empty() && fileline[fileline.length()-1] == '\r') {
			fileline.erase(fileline.length()-1);
		}
		for (std::string instr : split_str(fileline, ";", true)) {
			instructions.push_back(instr); 
		}
	}
	readfile.close();
	return instructions;
}

size_t str_to_size_t(const std::string num_s)
{
	//std::cerr << "\"" << num_s << "\"" << stoi(num_s)+1 << std::endl;
	if (num_s.substr(0,2) == "0x") {
		return (size_t) stoi(num_s.substr(2), 0, 16);
	}
	else {
		return (size_t) stoi(num_s);
	}
}

const std::string name_static_symbol(const size_t offset)
{
	std::string name("_static_");
	name = name + std::to_string(offset);
	return name;
}
