#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

//! Processes all command line arguments

/**
 * Flags if mpags-cipher should encrypt or decrypt the message provided
 */
enum class CipherMode {
	decrypt,
	encrypt
};

enum class CipherType {
	caesar,
	playfair,
	vigenere
};

/**
 * All the flags that the user can give when running mpags-cipher
 */
struct CmdlineInfo{
	bool error_flag = false;
	bool h_flag = false;
	bool v_flag = false;
	bool i_flag = false;
	bool o_flag = false;
	std::string iFile;
	std::string oFile;
	bool c_flag = false;
	CipherMode mode = CipherMode::encrypt;
	bool key_flag = false;
	std::string key = "";
	CipherType cipher;
	
	
};

/**
 * processCommandLine takes in all the provided cmd line arguments
 * and raises the appropriate flags required
 */
void processCommandLine(const int argc, char* argv[], CmdlineInfo& flags);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
