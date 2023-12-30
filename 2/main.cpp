#include "modAlphaCipher.h"

void check(const std::string& Text, const std::string& key)
{
    try {
        std::string cipherText;
        std::string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        int intKey = std::stoi(key);
        if (intKey <= 0)
            throw cipher_error(std::string("Invalid key ") + key);

		

        modAlphaCipher cipher(intKey);
        cipherText = cipher.encrypt(Text);
        decryptedText = cipher.decrypt(cipherText);
        std::cout << "key = " << key << std::endl;
        std::cout << "Encrypted text: " << cipherText << std::endl;
        std::cout << "Decrypted text: " << decryptedText << std::endl;
    } catch (const cipher_error & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "" << std::endl;
}

int main()
{
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","0");
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","");
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","5");
    check("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG","100");
    check("123","5");
    
    return 0;
}
