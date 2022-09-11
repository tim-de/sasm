#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <tclap/CmdLine.h>
#include "Symbol.hpp"
#include "SymTab.hpp"
#include "SymList.hpp"
#include "utils.hpp"



int main(int argc, char** argv)
{
	// Parse command line arguments and options with TCLAP
	bool binary, loader;
	std::string infile, outfile;
	int width, entry;
	try {
		TCLAP::CmdLine cmd("Assembler for subleq assembly language.", ' ', "0.1");

		// Add options here

		TCLAP::SwitchArg binaryswitch("b", "binary", "Output in raw binary format, default is space separated ASCII", cmd, false);
		
		TCLAP::SwitchArg loaderswitch("l", "loader", "In binary mode, prepend program size for use with bootloader", cmd, false);

		TCLAP::ValueArg<int> bitwidth("w", "width", "Address bus width, can be 8, 16, or 32", false, 8, "integer", cmd);

		TCLAP::ValueArg<int> entryarg("e", "entry", "Address of entry point for program", false, 0, "integer", cmd);

		TCLAP::ValueArg<std::string> outfilename("o", "outfile", "Output file name", false, "", "string", cmd);

		TCLAP::UnlabeledValueArg<std::string> infilename("infile", "Input file name", false, "in.sq", "string", cmd);
		// End of option specifiers

		// Parse argc and argv
		cmd.parse(argc, argv);
		
		// Collect into variables
		binary = binaryswitch.getValue();
		loader = loaderswitch.getValue();
		width = bitwidth.getValue();
		entry = entryarg.getValue();
		infile = infilename.getValue();
		outfile = outfilename.getValue();

	} catch (TCLAP::ArgException &e)
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
	// End of command line parsing
	
	//Adjust received arguments as necessary

	std::vector<std::string> instructions = get_instructions(infile);

	SymTab table;
	SymList list(entry, itowidth(width));

	int ret = list.parseFile(instructions, table);

	//std::cout << "Parse return code: " << ret << std::endl;

	if (binary) {
		list.binaryOut(loader);
	}
	else {
		list.printOut();
	}
}
