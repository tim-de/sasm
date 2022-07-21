#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <tclap/CmdLine.h>
#include "Symbol.h"
#include "Instruction.h"
#include "utils.h"



int main(int argc, char** argv)
{
	// Parse command line arguments and options with TCLAP
	bool debug;
	std::string infile, outfile;
	try {
		TCLAP::CmdLine cmd("Assembler for subleq assembly language.", ' ', "0.1");

		// Add options here
		TCLAP::SwitchArg debugswitch("d", "debug", "Print debug information", cmd, false);

		TCLAP::ValueArg<std::string> outfilename("o", "outfile", "Output file name", false, "", "string", cmd);

		TCLAP::UnlabeledValueArg<std::string> infilename("infile", "Input file name", false, "in.sq", "string", cmd);
		// End of option specifiers

		// Parse argc and argv
		cmd.parse(argc, argv);
		
		// Collect into variables
		debug = debugswitch.getValue();
		infile = infilename.getValue();
		outfile = outfilename.getValue();

	} catch (TCLAP::ArgException &e)
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
	// End of command line parsing

	// Instantiate file object
	std::ifstream readFile(infile);
	
	std::string fileline;
	while (getline( readFile, fileline )) {
		std::cout << "in : " << fileline << std::endl;
		for (std::string line : split_str(fileline, ";", true)) {
			//if (line.length() != 0) {
			if (1) {
				std::cout << "out: " << line << std::endl;
			}
		}
	}
	readFile.close();
}
