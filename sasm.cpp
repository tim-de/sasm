#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <tclap/CmdLine.h>
#include "Symbol.h"
#include "Instruction.h"

std::vector<std::string> split_str(std::string s, std::string delimiter) {
	std::vector<std::string> s_split;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s_split.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	s_split.push_back(s);
	return s_split;
}


int main(int argc, char** argv)
{
	std::string infile;
	bool debug;
	try {
		TCLAP::CmdLine cmd("Assembler for subleq assembly language.", ' ', "0.1");

		TCLAP::SwitchArg debugSwitch("d", "debug", "Print debug information", cmd, false);

		TCLAP::UnlabeledValueArg<std::string> infileName("ifilename", "Input file name", false, "in.sq", "string", cmd);


		cmd.parse(argc, argv);
		
		debug = debugSwitch.getValue();
		infile = infileName.getValue();
	} catch (TCLAP::ArgException &e)
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }

	std::ifstream readFile(infile);
	
	std::string fileline;
	//std::vector instructions;
	while (getline (readFile, fileline)) {
		for (std::string line : split_str(fileline, ";")) {
			if (line.length() != 0) {
				std::cout << line << std::endl;
			}
			//instructions.push_back(line);
		}
	}
	readFile.close();
}
