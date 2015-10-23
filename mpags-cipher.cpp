//! Main implementation of the mpags-cipher program
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

	for(int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

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
