#include <iostream>
#include <string>
#include <algorithm>
#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(std::string& key, const CipherMode& mode)
  : mode_{mode}
{
	setKey(key);
}

void PlayfairCipher::setKey(std::string& key) {
	//Store the original key
	key_ = key;

	//Append the alphabet
	std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	key += alphabet;

	//Make sure the key is upper case
	std::transform(key.begin(), key.end(), key.begin(), toupper);
	std::cout << key << std::endl;

	//Remove non-alpha characters
	auto isNalpha = [] (char lett) {
		return (!isalpha(lett));
	};
	auto rmviter = std::remove_if(key.begin(), key.end(), isNalpha);
	key.erase(rmviter,key.end());

	//Change J->I
	auto rmvJ = [] (char c) {
		char i{'I'};
		if (c == 'J') return i;
		else return c;
	};
	std::transform(key.begin(), key.end(), key.begin(), rmvJ);

	//Remove duplicated letters
	std::string uniq_lett;
	auto rmv_lett = [&] (char c) {
		
	};	
	//Store the coords of each letter
	//
	//Store the playfair cipher key map
	std::cout << key << std::endl;
}

std::string PlayfairCipher::encrypt(const std::string& message) const{
	//Make sure input is valid
	//Upper case, only chars and J->I
	
	//Find repeated chars and add an X
	
	//If the size is off, add a trailing Z
	
	//Loop over the input in Digraphs
	
	//Find the coords in the grid for each digraph
	
	//For each digraph, decide how to encrypt
	
	//Return the text

	return message;
}

std::string PlayfairCipher::decrypt(const std::string& message) const{
	return message;
}
