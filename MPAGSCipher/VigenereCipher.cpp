#include <string>
#include <algorithm>
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher(std::string& key, const CipherMode& mode)
  : mode_{mode}
{
	setKey(key);
}

void VigenereCipher::setKey(std::string& key) {
	//Store the original key
	key_ = key;
	
}

std::string VigenereCipher::encrypt(const std::string& message) const{
	return message;
}

std::string VigenereCipher::decrypt(const std::string& message) const{
	return message;
}
	
