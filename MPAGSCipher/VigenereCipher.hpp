#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "ProcessCommandLine.hpp"
#include "Cipher.hpp"

//! De/encrypt a message using the Vigenere cipher

/**
 * Vigenere Cipher
 *
 */

class VigenereCipher : public Cipher {
  public:
	VigenereCipher(std::string& key, const CipherMode& mode);
	
	std::string encrypt(const std::string& message) const override;
	std::string decrypt(const std::string& message) const override;

  private:
	void setKey(std::string& key);

	std::string key_;
	const CipherMode mode_;
};

#endif // MPAGSCIPHER_VIGENERECIPHER_HPP
