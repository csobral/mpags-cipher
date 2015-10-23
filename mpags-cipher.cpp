//! Main implementation of the mpags-cipher program
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	
	//Runs through command line arguments
	int exit_flag{0}; //if --help and/or --version are called, print then exit
	for(int i = 0; i < argc; ++i) {
		
		std::string arg{argv[i]}; //Converts c-style to c++ style string
		
		//Looks for a help flag, prints "helpful" advice and exits program
		if(arg == "--help" || arg == "-h") {
			std::cout << "This program de/encrypts plain text using 3 classic ciphers" << std::endl;
			exit_flag = 1;
		}
		//Prints mpags-cipher version if prompted
		else if(arg == "--version") {
			std::cout << "mpags-cipher v0.3.0" << std::endl;
			exit_flag = 1;
		}
		//Gets input file from argument
		else if(arg == "-i") {
			
		}
	}

	//Checks whether program should exit
        if(exit_flag == 1) return(0);

	char in_char{'x'};
	std::string output{"0"}; 
	while(std::cin >> in_char) //Keeps looking for input until user presses ctrl+D
	{
		//Checks whether input is number, lower, or upper case letter. Disregards input otherwise
		if(isdigit(in_char)) {
			switch(in_char) {
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
		else if(islower(in_char)) {
			output = toupper(in_char);
		}
		else if(isupper(in_char)){
			output = in_char;
		}
	std::cout << output << std::endl;
	}

  return 0;
}
