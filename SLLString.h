#ifndef SLLSTRING_H
#define SLLSTRING_H
#include <iostream>
#include <string>
#include "CharacterNode.h"

class SLLString {

public:

    SLLString();
    SLLString(const std::string& inputString);
    SLLString(const SLLString& inputString);
    ~SLLString();

    //assigns a string to the SLL
    SLLString& operator=(const SLLString& inputString);

    //concatenates two SLLStrings
    SLLString& operator+=(const SLLString& inputString);

    //prints the given SLLString
    friend std::ostream& operator<<(std::ostream& outputStream, const SLLString& inputString);

    //get the character at index n
    char& operator[](const int n) const;

    //gets the length of the string including spaces
    int length() const;

    //finds the index of the first occurrence of substring in the current string
    //(the index where the substring starts)
    int findSubstring(const std::string substring) const;

    //erases all occurrences of the given character from the current string
    void erase(char character);

private:
    CharacterNode* m_pHeadOfString;
    CharacterNode* m_pTailOfString;
    int m_stringLength;

};

#endif