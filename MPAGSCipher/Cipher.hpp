#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

//! Virtual Cipher class from which the specific ciphers implementations inherit
class Cipher {
  public:
	Cipher() = default;
	Cipher(const Cipher& ciph) = default;
	Cipher(Cipher&& ciph) = default;
	Cipher& operator=(const Cipher& ciph) = default;
	Cipher& operator=(Cipher&& ciph) = default;
	virtual ~Cipher() = default;

	virtual std::string encrypt(const std::string& input) const = 0;
	virtual std::string decrypt(const std::string& input) const = 0;
};

#endif // MPAGSCIPHER_CIPHER_HPP
