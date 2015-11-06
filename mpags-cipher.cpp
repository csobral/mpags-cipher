//! Main implementation of the mpags-cipher program

// Standard Libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "CaesarCipher.hpp"

template <typename T>
void readStream(T& inputstream, std::string& message) {
	inputstream >> message;
}

int main(int argc, char* argv[]) {
	
	//Initialise command line argument flags
	bool error_flag{false}; //Zero if all arguments are valid. See errorCases for detailed error info
	bool exit_flag{false}; //if --help and/or --version are called, print then exit
	bool h_flag{false}; //Help flag. True if --help or -h argument found
	bool v_flag{false}; //Version flag. True if --version argument found
	bool i_flag{false}; //Input file flag. True if -i argument found
	bool o_flag{false}; //Output file flag. True if -o argument found
	bool decrypt{false}; //Decryption flag. True if --decrypt found
	bool key_flag{false}; //True if a cipher key is given
	int key{0}; //Cipher key
	
	//Strings that hold in/output file names
	std::string iFile{"input"};
	std::string oFile{"output"};

	//Vector to hold stream of characters
	std::string message{""};
	std::string trans_msg{""};

	//Check which flags the user has raised
	processCommandLine(argc, argv, error_flag, h_flag, v_flag, i_flag, o_flag, iFile, oFile, decrypt, key_flag, key);

	if(h_flag) { //If user asked for help
		std::cout << "This program de/encrypts plain text using 3 classic ciphers" << std::endl;
		exit_flag = true;
	}

	if(v_flag) { //If user asked for version number
		std::cout << "mpags-cipher v0.5.0" << std::endl;
		exit_flag = true;
	}

	//Checks whether program should exit
	if(error_flag) return(1);
	else if(!key_flag) {
		std::cout << "A CIPHER KEY MUST BE PROVIDED!" << std::endl;
		return(1);
	}
        else if(exit_flag) return(0);

	if(!i_flag) readStream(std::cin, message); //If no input file given, read from std::cin
	else{
		std::ifstream in_file{iFile}; //Open input stream from file provided
		if(!in_file.good()) { //Read from std::cin if the file can't be opened
			std::cout << "CANNOT OPEN INPUT FILE!" << std::endl;
			std::cout << "SWITCHING TO KEYBOARD INPUT" << std::endl;
			readStream(std::cin, message);
		}
		else readStream(in_file, message); //Read from file if it opened OK
	}

	for(const char ele : message) { //Transform message into cipherable text
		trans_msg += transformChar(ele); //Spells out numbers, all letters uppercase
	}
	
	std::string output{CaesarCipher(trans_msg, decrypt, key)};
	std::cout<< output << std::endl;	
	
	return 0;
}

