#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include "ProcessCommandLine.hpp"
#include "Cipher.hpp"

//! De/encrypt a message using the Playfair cipher


/**
 * Playfair Cipher
 *
 */

class PlayfairCipher : public Cipher {
  public:
	PlayfairCipher(std::string& key, const CipherMode& mode);
	
	std::string encrypt(const std::string& message) const override;
	std::string decrypt(const std::string& message) const override;

  private:
	void setKey(std::string& key);

	std::string key_;
	const CipherMode mode_;
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
