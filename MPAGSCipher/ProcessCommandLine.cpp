#include <iostream>
#include <string>
#include "ProcessCommandLine.hpp"

void processCommandLine(const int argc, char* argv[], CmdlineInfo& flags) {
	/*
	 * Function: Check which flags/options were given as arguments to mpags-cipher
	 * 
	 * argc: # of command line arguments
	 * argv[]: C-style array of arguments
	 * error_flag: 'true' if there are any problems with user input
	 * h_flag: 'true' if user asks for help
	 * v_flag: 'true' if user asks for version number
	 * i_flag: 'true' if user supplies input file
	 * o_flag: 'true' if user supplies output file
	 * c_flag: 'true' if user has specified which cipher to use
	 * decrypt: 'true' if user chooses to decrypt rather than encrypt
	 * key_flag: 'true' if user supplies a key with argument '-k'
	 * */

	std::string arg{""}; //Temp string for comparing
	
	for(int i = 0; i < argc; ++i) { //Loop over all command line arguments

		arg = argv[i]; //Convert c-style to c++ style string
		
		//Check if prompted for help
		if(arg == "--help" || arg == "-h") flags.h_flag = true;
		
		//Check if prompted for version number
		else if(arg == "--version") flags.v_flag = true;
		
		//Check if program should de/encrypt
		else if(arg == "--decrypt") flags.mode = CipherMode::decrypt;
		
		//Check if user supplied a cipher key
		else if(arg == "-k") {
			if(i == (argc-1)) { //If it's the last argument
				flags.error_flag = true;
				std::cout << "Please specify a cipher key using the arguments:\n"
                                 << "-k key" << std::endl;
			}
			else if(argv[i+1][0] == '-') {
				flags.error_flag = true;
				std::cout << "Please provide a valid key!" << std::endl;
			}
			else {
				flags.key = argv[i+1]; //Get key from list of arguments
				flags.key_flag = true;
			}
		}
		
		//Check if user specified which cipher should be used
		else if(arg == "--cipher") {
			if(i == (argc-1)) { //If it's the last argument
				flags.error_flag = true;
				std::cout << "Please specify what cipher should be used with:\n"
                                 << "--cipher ciphername\n" 
				 << "ciphername = caesar || playfair || vigenere" << std::endl;
			}
			else {
				std::string ciphstr = argv[i+1];
				if(ciphstr == "caesar"){
					flags.cipher = CipherType::caesar;
					flags.c_flag = true;
				}
				else if(ciphstr == "playfair") {
					flags.cipher = CipherType::playfair;
					flags.c_flag = true;
				}
				else if(ciphstr == "vigenere") {
					flags.cipher = CipherType::vigenere;
					flags.c_flag = true;
				}
				else {
					flags.error_flag = true;
					std::cout << "Please provide a valid cipher type!\n"
				 	<< "Valid ciphers: caesar, playfair, vigenere" << std::endl;
				}
			}
		}	

		//Check if user supplied input file
		else if(arg == "-i") {
			if(i == (argc-1)) { //If it's the last argument
				flags.error_flag = true;
				std::cout << "Please specify an input file with the arguments:\n"
                                 << "-i input_file_name" << std::endl;
			}
			else if(argv[i+1][0] == '-') {
				flags.error_flag = true;
				std::cout << "Cannot recognise input file name!" << std::endl;
			}
			else {
				flags.i_flag = true;
				flags.iFile = argv[i+1]; //Get file name from list of arguments

			}
		}

		//Check if user supplied output file
		else if(arg == "-o") {
			if(i == (argc-1)) { //If it's the last argument
				flags.error_flag = true;
				std::cout << "Please specify an output file with the arguments:\n"
                                 << "-o output_file_name" << std::endl;
			}
			else if(argv[i+1][0] == '-') {
				flags.error_flag = true;
				std::cout << "Cannot recognise output file name!" << std::endl;
			}
			else {
				flags.o_flag = true;
				flags.oFile = argv[i+1]; //Get file name from list of arguments

			}
		}
	}
}
