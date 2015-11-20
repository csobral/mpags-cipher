#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "ProcessCommandLine.hpp"

//! De/encrypt a message using the Vigenere cipher

/**
 * Vigenere Cipher
 *
 */

class VigenereCipher {
  public:
	VigenereCipher(std::string& key);
	
	std::string encrypt(const std::string& message):

  private:
	void setKey(std::string& key);

	std::string key_;
};

#endif // MPAGSCIPHER_VIGENERECIPHER_HPP
