#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "ProcessCommandLine.hpp"

//! De/encrypt a message using the Caesar cipher

/**
 * Caesar Cipher contains an integer key and an enum flagging
 * whether to encrypt or decrypt a message.
 *
 * Create a CaesarCipher object using CaesarCipher object(key,mode)
 * Decrypt/Encrypt a message with object.encode(message)
 */
class CaesarCipher {
  public:
	/**
 	* Create a new CaesarCipher object with a key provided
 	* by the user and an enum 'mode'
 	*
 	* \param key The integer cipher key
 	* \param mode The flag that checks if cipher is running in decrypt mode
 	*/
	CaesarCipher(const int& key, const CipherMode& mode);

	/**
	* Decrypt/Encrypt a message provided by the user
	* using the key provided by them
	*
	* \param message The message the user wants to de/encrypt
	*/ 
	std::string encode(const std::string& message);

  private:
	/**
	* Find the position of each letter in the alphabet used
	* Standard English is hard-coded for the moment
	* 	A = 0, Z = 25
	*
	* \param lett The letter we want the position of
	* \param alphabet The alphabet being used
	*/
	int findPos(const char& lett, const std::string& alphabet);
	
	/// \param The key provided by the user
	int key_;

	/// \param Flag the checks whether cipher is running in decrypt mode
	const CipherMode mode_;
};


#endif // MPAGSCIPHER_CAESARCIPHER_HPP
