#include "modAlphaCipher.h"

std::string modAlphaCipher::decrypt(const std::string& cipher_text)              
{
    std::string text = getValidText(cipher_text);
    std::string decrypted_text = text;
    int length, num_of_rows, position, index; 
    length = text.size();
    num_of_rows = (length - 1) / num_of_columns + 1;
    index = 0;
    for (int column_number = num_of_columns; column_number > 0; column_number--) { 
        for (int row_number = 0; row_number < num_of_rows; row_number++) { 
            position = num_of_columns * row_number + column_number;
            if (position - 1 < length) {
                decrypted_text[position - 1] = text[index];
                index++;
            }
        }
    }
    return decrypted_text;
}

std::string modAlphaCipher::encrypt(const std::string& text)                     
{
    std::string open_text = getValidText(text);
    std::string encrypted_text = open_text;
    int length, num_of_rows, position, index; 
    length = open_text.size();
    num_of_rows = (length - 1) / num_of_columns + 1; 
    index = 0;
    for (int column_number = num_of_columns; column_number > 0; column_number--) { 
        for (int row_number = 0; row_number < num_of_rows; row_number++) {
            position = column_number + num_of_columns * row_number;
            if (position - 1 < length) {
                encrypted_text[index] = open_text[position - 1];
                index++;
            }
        }
    }
    return encrypted_text;
}

inline std::string modAlphaCipher::getValidText(const std::string & text)
{
    std::string tmp;
    for (auto c:text) {
        if (isalpha (c)) {
            if (islower (c))
                tmp.push_back(toupper(c));
                else
                    tmp.push_back(c);
        }
    }
    return tmp;
}
