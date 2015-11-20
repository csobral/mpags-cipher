#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP
#include <memory>
#include "ProcessCommandLine.hpp"
#include "Cipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType& type, std::string& key, const CipherMode& mode);

#endif // MPAGSCIPHER_CIPHERFACTORY_HPP
