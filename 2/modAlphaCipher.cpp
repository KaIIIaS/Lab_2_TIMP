#include "modAlphaCipher.h"

string modAlphaCipher::decrypt(const std::string& cipher_text)              
{
    string valid_text = getValidText(cipher_text);
    string original_text = valid_text;
    int length, num_columns, position, index; 
    length = valid_text.size();
    num_columns = (length - 1) / num_rows + 1;
    index = 0;
    for (int column_number = num_columns; column_number > 0; column_number--) { 
        for (int row_number = 0; row_number < num_rows; row_number++) { 
            position = num_rows * row_number + column_number;
            if (position - 1 < length) {
                original_text[position - 1] = valid_text[index];
                index++;
            }
        }
    }
    return original_text;
}

string modAlphaCipher::encrypt(const string& original_text)                     
{
    string valid_text = getValidText(original_text);
    string cipher_text = valid_text;
    int length, num_columns, position, index; 
    length = valid_text.size();
    num_columns = (length - 1) / num_rows + 1; 
    index = 0;
    for (int column_number = num_columns; column_number > 0; column_number--) { 
        for (int row_number = 0; row_number < num_rows; row_number++) {
            position = column_number + num_rows * row_number;
            if (position-1 < length) {
                cipher_text[index] = valid_text[position-1];
                index++;
            }
        }
    }
    return cipher_text;
}

inline std::string modAlphaCipher::getValidText(const std::string & str)
{
    string tmp;
    for (auto c:str) {
        if (isalpha (c)) {
            if (islower (c))
                tmp.push_back(toupper(c));
            else
                tmp.push_back(c);
        }
    }

    if (tmp.empty())
        throw cipher_error ("Empty open text");
    return tmp;
}
