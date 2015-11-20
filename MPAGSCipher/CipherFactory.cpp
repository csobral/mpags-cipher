#include <memory>
#include <string>
#include "CipherFactory.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType& type, std::string& key, const CipherMode& mode) {

	switch(type) {
	  case CipherType::caesar :
		return std::make_unique<CaesarCipher>(stoi(key), mode);
	  
	  case CipherType::playfair :
		return std::make_unique<PlayfairCipher>(key, mode);
	  
	  case CipherType::vigenere :
		return std::make_unique<VigenereCipher>(key, mode);
	}
	return std::unique_ptr<Cipher> (nullptr);
}
