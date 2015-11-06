#include <iostream>
#include <string>

bool processCommandLine(const int argc, char* argv[], bool& error_flag, bool& h_flag, bool& v_flag, bool& i_flag, bool& o_flag, std::string& iFile, std::string& oFile, bool& decrypt, bool& key_flag, int& key) {
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
	 * decrypt: 'true' if user chooses to decrypt rather than encrypt
	 * key_flag: 'true' if user supplies a key with argument '-k'
	 * */

	std::string arg{""}; //Temp string for comparing
	
	for(int i = 0; i < argc; ++i) { //Loop over all command line arguments

		arg = argv[i]; //Convert c-style to c++ style string
		
		//Check if prompted for help
		if(arg == "--help" || arg == "-h") h_flag = true;
		
		//Check if prompted for version number
		else if(arg == "--version") v_flag = true;
		
		//Check if program should de/encrypt
		else if(arg == "--decrypt") decrypt = true;
		
		//Check if user supplied a cipher key
		else if(arg == "-k") {
			if(i == (argc-1)) { //If it's the last argument
				error_flag = true;
				std::cout << "Please specify a cipher key using the arguments:\n"
                                 << "-k integer_key" << std::endl;
			}
			/*else if(argv[i+1][0] == '-') {
				error_flag = true;
				std::cout << "Cannot recognise cipher key!" << std::endl;
			}*/
			else {
				key = std::stoi(argv[i+1]); //Get key from list of arguments
				key_flag = true;
			}
		}
			

		//Check if user supplied input file
		else if(arg == "-i") {
			if(i == (argc-1)) { //If it's the last argument
				error_flag = true;
				std::cout << "Please specify an input file with the arguments:\n"
                                 << "-i input_file_name" << std::endl;
			}
			else if(argv[i+1][0] == '-') {
				error_flag = true;
				std::cout << "Cannot recognise input file name!" << std::endl;
			}
			else {
				i_flag = true;
				iFile = argv[i+1]; //Get file name from list of arguments

			}
		}

		//Check if user supplied output file
		else if(arg == "-o") {
			if(i == (argc-1)) { //If it's the last argument
				error_flag = true;
				std::cout << "Please specify an output file with the arguments:\n"
                                 << "-o output_file_name" << std::endl;
			}
			else if(argv[i+1][0] == '-') {
				error_flag = true;
				std::cout << "Cannot recognise output file name!" << std::endl;
			}
			else {
				o_flag = true;
				oFile = argv[i+1]; //Get file name from list of arguments

			}
		}
	}

	return error_flag;
}
