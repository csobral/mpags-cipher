#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

//! Processes all command line arguments
bool processCommandLine(const int argc, char* argv[], bool& error_flag, bool& h_flag, bool& v_flag, bool& i_flag, bool& o_flag, std::string& iFile, std::string& oFile, bool& decrypt, bool& key_flag, int& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
