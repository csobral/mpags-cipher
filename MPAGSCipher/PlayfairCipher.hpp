#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include "ProcessCommandLine.hpp"

//! De/encrypt a message using the Playfair cipher


/**
 * Playfair Cipher
 *
 */

class PlayfairCipher {
  public:
	PlayfairCipher(std::string& key, const CipherMode& mode);
	
	std::string encrypt(const std::string& message);

  private:
	void setKey(std::string& key);

	std::string key_;
	const CipherMode mode_;
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
