#include <string>
#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const int& key, const CipherMode& mode)
  : key_{key}, mode_{mode}
{
}

int CaesarCipher::findPos(const char& lett, const std::string& alphabet) { 
	
	int pos{0};
	for(unsigned int i = 0; i < alphabet.size(); ++i) {
		if(lett == alphabet[i]) pos = i;
	}
	
	return pos;
}

std::string CaesarCipher::encrypt(const std::string& message) {
	
	std::string ciphertext{""}; //String to hold ciphered message
	std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //The alphabet to find letter position
	int abc_pos{0}; //Position in the alphabet of specific letter (A=0,Z=25)
	int ciph_pos{1}; //Position of ciphered letter in the alphabet

	if(mode_ == CipherMode::decrypt) key_= -key_; //if decrypting, key becomes negative

	for(const char& lett : message) { //For each letter in the original message
		abc_pos = findPos(lett, alphabet); //Get alphabet position of original char
		ciph_pos = (abc_pos + key_) % alphabet.size(); //Get position of ciphered char
		ciphertext += alphabet[ciph_pos]; //Get the de/encrypted message
	}
	
	return ciphertext;
}

