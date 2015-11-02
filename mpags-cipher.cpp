//! Main implementation of the mpags-cipher program

// Standard Libraries
#include <iostream>
#include <string>
#include <fstream>

// Project headers
#include "TransformChar.hpp"


bool processCommandLine(const int argc, char* argv[], bool& error_flag, bool& exit_flag, bool& h_flag, bool& v_flag, bool& rf_flag, bool& wf_flag, std::string& iFile, std::string& oFile);

int main(int argc, char* argv[]) {
	
	//Initialise command line argument flags
	bool error_flag{false};
	bool exit_flag{false}; //if --help and/or --version are called, print then exit
	bool h_flag{false}; //Help flag. True if --help or -h argument found
	bool v_flag{false}; //Version flag. True if --version arguement found
	bool rf_flag{false}; //Read-from-file flag. If true, reads input from file, not keyboard
	bool wf_flag{false}; //Write-to-file flag. If true, writes output to file, not terminal

	std::string iFile{"input.txt"};
	std::string oFile{"output.txt"};
	
	processCommandLine(argc, argv, error_flag, exit_flag, h_flag, v_flag, rf_flag, wf_flag, iFile, oFile);
	if(h_flag) std::cout << "This program de/encrypts plain text using 3 classic ciphers" << std::endl;
	if(v_flag) std::cout << "mpags-cipher v0.3.0" << std::endl;

	//Checks whether program should exit
	if(error_flag == true) {
		std::cout << "ERROR: NO IN/OUTPUT FILE GIVEN" << std::endl;
		return(1);
	}
        else if(exit_flag == true) return(0);

	char in_char{'x'};
	std::string output{"0"}; 
	while(std::cin >> in_char) //Keeps looking for input until user presses ctrl+D
	{
		output = transformChar(in_char); //Takes input character and returns a string
		if(output != "0") std::cout << output << std::endl;
	}

  return 0;
}

bool processCommandLine(const int argc, char* argv[], bool& error_flag, bool& exit_flag, bool& h_flag, bool& v_flag, bool& rf_flag, bool& wf_flag, std::string& iFile, std::string& oFile) {
	/*
	 * Function: Check which flags/options were given as arguments to mpags-cipher
	 * 
	 * argc: # of command line arguments
	 * argv[]: C-style array of arguments
	 * error_flag: 'true' if there are any problems with user input
	 * exit_flag: 'true' if user asks for help / version number
	 * h_flag: 'true' if user asks for help
	 * v_flag: 'true' if user asks for version number
	 * rf_flag: 'true' if user specifies input comes from file
	 * wf_flag: 'true' if user specifies output will go to file
	 * */
	std::string arg{""};
	
	for(int i = 0; i < argc; ++i) {
		arg = argv[i]; //Converts c-style to c++ style string

		//If in\output flag is the last argument, raise an error + close
		if(i == argc-1 && (arg == "-i" || arg == "-o")){
			error_flag = true;
		}
		else {
			if(arg == "--help" || arg == "-h") { //Looks for a help flag
				h_flag = true;
				exit_flag = true;
			}
			else if(arg == "--version") { //Checks if prompted for version number
				v_flag = true;
				exit_flag = true;
			}
			else if(arg == "-i") {
				iFile = argv[i+1];
				i++;
			}
			else if(arg == "-o") {
				oFile = argv[i+1];
				i++;
			}
			else if(arg == "-rf") {
				rf_flag = true;
			}
                        else if(arg == "-wf") {
                                wf_flag = true;
                        }
		}
	}
	
return error_flag;
}

