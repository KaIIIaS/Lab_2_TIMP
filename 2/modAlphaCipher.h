#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;

class modAlphaCipher
{
private:
    const int num_of_columns;
    string getValidText(const std::string & str);
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const int& key) :num_of_columns(key) {};    //конструктор
    string encrypt(const string& open_text);               //зашифрование
    string decrypt(const string& cipher_text);             //расшифрование
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
