//! Main implementation of the mpags-cipher program
#include <iostream>
#include <string>
#include <fstream>

std::string transformChar(const char inputc) {
	/*
	 * Function takes a single character from keyboard input.
	 * If character was a letter, it returns that letter in uppercase
	 * If character was a number, it returns the word for that number (1->"ONE")
	 *
	 * Argument is a single char and the function returns a string.
	 * */

	std::string output{"0"};

	//Checks whether input is number, lower, or upper case letter. Disregards input otherwise
	if(isdigit(inputc)) {
		switch(inputc) {
			case('0'): output = "ZERO"; break;
			case('1'): output = "ONE"; break;
			case('2'): output = "TWO"; break;
			case('3'): output = "THREE"; break;
			case('4'): output = "FOUR"; break;
			case('5'): output = "FIVE"; break;
			case('6'): output = "SIX"; break;
			case('7'): output = "SEVEN"; break;
			case('8'): output = "EIGHT"; break;
			case('9'): output = "NINE"; break;
		}
	}
	else if(islower(inputc)) {
		output = toupper(inputc);
	}
	else if(isupper(inputc)){
		output = inputc;
	}
	
	return output;
}

bool processCommandLine(const int argc, char* argv[], bool& error_flag, bool& exit_flag, bool& h_flag, bool& v_flag, std::string& iFile, std::string& oFile) {
	
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
			else if(arg == "--version") { //Checks if prompted for version#
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
		}
	}
	
return error_flag;
}

int main(int argc, char* argv[]) {
	
	//Runs through command line arguments
	bool error_flag{false};
	bool exit_flag{false}; //if --help and/or --version are called, print then exit
	bool h_flag{false}; //Help flag. True if --help or -h argument found
	bool v_flag{false}; //Version flag. True if --version arguement found
	//bool rf_flag{false}; //Read-from-file flag. If true, reads input from file, not keyboard
	//bool wf_flag{false}; //Write-to-file flag. If true writes output to file, not terminal

	std::string iFile{"input.txt"};
	std::string oFile{"output.txt"};
	
	processCommandLine(argc, argv, error_flag, exit_flag, h_flag, v_flag, iFile, oFile);
	if(h_flag) std::cout << "This program de/encrypts plain text using 3 classic ciphers" << std::endl;
	if(v_flag) std::cout << "mpags-cipher v0.3.0" << std::endl;

	//Checks whether program should exit
	if(error_flag == true) {
		std::cout << "ERROR: NO IN/OUTPUT FILE GIVEN" << std::endl;
		return(1);
	}
        if(exit_flag == true) return(0);

	char in_char{'x'};
	std::string output{"0"}; 
	while(std::cin >> in_char) //Keeps looking for input until user presses ctrl+D
	{
		output = transformChar(in_char); //Takes input character and returns a string
		if(output != "0") {
			std::cout << output << std::endl;
		}
	}

  return 0;
}
