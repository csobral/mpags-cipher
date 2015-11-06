#include <string>

std::string transformChar(const char inputc) {
	/*
	 * Function takes a single character from keyboard input.
	 * If character was a letter, it returns that letter in uppercase
	 * If character was a number, it returns the word for that number (1->"ONE")
	 *
	 * Argument is a single char and the function returns a string.
	 * */
	std::string output{""};

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
