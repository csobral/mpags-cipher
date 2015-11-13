//! Main implementation of the mpags-cipher program

// Standard Libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

template <typename T>
void readStream(T& inputstream, std::string& message) {
	std::getline(inputstream,message);
}

int main(int argc, char* argv[]) {
	
	//Initialise command line argument flags
	CmdlineInfo flags;
	bool exit_flag{false}; //if --help and/or --version are called, print then exit

	//Vector to hold stream of characters
	std::string message{""};
	std::string trans_msg{""};

	//Check which flags the user has raised
	processCommandLine(argc, argv, flags);

	if(flags.h_flag) { //If user asked for help
		std::cout << "This program de/encrypts plain text using 3 classic ciphers" << std::endl;
		exit_flag = true;
	}

	if(flags.v_flag) { //If user asked for version number
		std::cout << "mpags-cipher v0.5.0" << std::endl;
		exit_flag = true;
	}

	//Checks whether program should exit
	if(flags.error_flag) return(1);
	else if(!flags.key_flag) {
		std::cout << "A CIPHER KEY MUST BE PROVIDED!" << std::endl;
		return(1);
	}
        else if(exit_flag) return(0);

	if(!flags.i_flag) readStream(std::cin, message); //If no input file given, read from std::cin
	else{
		std::ifstream in_file{flags.iFile}; //Open input stream from file provided
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
	

	CaesarCipher cipher(flags.key, flags.mode);
	std::cout<< cipher.encode(trans_msg) << std::endl;	
	
	return 0;
}

