#include "SLLString.h"

//empty constructor
SLLString::SLLString() : m_pHeadOfString(nullptr), m_pTailOfString(nullptr), m_stringLength(0) {}

//constructor with string parameter
SLLString::SLLString(const std::string& inputString) : m_pHeadOfString(nullptr), m_pTailOfString(nullptr), m_stringLength(0) {

    for (int i = 0; i < inputString.length(); i++) {

        char character = inputString[i];
        CharacterNode* newNode = new CharacterNode(character);

        if (!m_pHeadOfString) {
            m_pHeadOfString = newNode;
            m_pTailOfString = newNode;

        } else {
            m_pTailOfString->m_next = newNode;
            m_pTailOfString = m_pTailOfString->m_next ;
        }

        m_stringLength++;
    }
}

//constructor with SLLString Parameter
SLLString::SLLString(const SLLString& inputString) : m_pHeadOfString(nullptr), m_pTailOfString(nullptr), m_stringLength(0) {

    CharacterNode* current = inputString.m_pHeadOfString;

    while (current) {

        CharacterNode* newNode = new CharacterNode(current->m_data);

        if (!m_pHeadOfString) {
            m_pHeadOfString = newNode;
            m_pTailOfString = newNode;

        } else {
            m_pTailOfString->m_next = newNode;
            m_pTailOfString = m_pTailOfString->m_next;
        }

        m_stringLength++;
        current = current->m_next;
    }
}

SLLString::~SLLString() {

    CharacterNode* current = m_pHeadOfString;

    while (current) {
        CharacterNode* nextNode = current->m_next;
        delete current;
        current = nextNode;
    }

    m_pHeadOfString = nullptr;
    m_pTailOfString = nullptr;
    m_stringLength = 0;
}

//create deep copy of the input string and assign it to the SLL
SLLString& SLLString::operator=(const SLLString& inputString) {

    if (this == &inputString) {
        return *this;
    }

    //since we are assigning the input string to the new SLL, we delete the old SLL to prevent any memory leaks
    this->~SLLString();

    CharacterNode* current = inputString.m_pHeadOfString;

    while (current) {

        CharacterNode* newNode = new CharacterNode(current->m_data);

        if (!m_pHeadOfString) {
            this->m_pHeadOfString = newNode;
            this->m_pTailOfString = newNode;

        } else {
            this->m_pTailOfString->m_next = newNode;
            this->m_pTailOfString = m_pTailOfString->m_next;

        }

        this->m_stringLength++;
        current = current->m_next;
    }

    return *this;
}

//concatenate two strings and assign resulting string
SLLString& SLLString::operator+=(const SLLString& inputString) {

    CharacterNode* current = inputString.m_pHeadOfString;

    while (current) {

        CharacterNode* newNode = new CharacterNode(current->m_data);

        if (!this->m_pHeadOfString) {
            this->m_pHeadOfString = newNode;
            this->m_pTailOfString = newNode;

        } else {
            this->m_pTailOfString->m_next = newNode;
            this->m_pTailOfString = m_pTailOfString->m_next;

        }

        this->m_stringLength++;
        current = current->m_next;
    }

    return *this;
}

//prints the SLLString
std::ostream& operator<<(std::ostream& outputStream, const SLLString& inputString) {

    CharacterNode* current = inputString.m_pHeadOfString;

    //traverses the SLL and adds each character to the output stream
    while (current) {
        outputStream << current->m_data;
        current = current->m_next;

    }

    return outputStream;
}

//gets the data located at a given index n
char& SLLString::operator[](const int n) const {

    CharacterNode* current = m_pHeadOfString;

    for (int i = 0; i < n && current != nullptr; i++) {
        current = current->m_next;
    }

    return current->m_data;
}

//returns the length of the string including spaces
int SLLString::length() const {
    return m_stringLength;
}

//returns the index of the first occurrence of substring in the current string
//returns -1 if the substring was not found
//capitalization matters
int SLLString::findSubstring(const std::string substring) const {

    CharacterNode* current = m_pHeadOfString;
    int index = 0;

    while (current) {
        CharacterNode* temp = current;
        int subStringIndex = 0;

        while (temp && subStringIndex < substring.length() && temp->m_data == substring[subStringIndex]) {
            temp = temp->m_next;
            subStringIndex++;
        }

        if (subStringIndex == substring.length()) {
            return index;
        }

        current = current->m_next;
        index++;
    }

    return -1;
}

//erases all occurrences of the given character from the SLLString
void SLLString::erase(char character) {

    CharacterNode* current = m_pHeadOfString;
    CharacterNode* prev = nullptr;

    while (current) {

        if (current->m_data == character) {
            if (prev) {
                prev->m_next = current->m_next;

            } else {
                m_pHeadOfString = current->m_next;

            }

            CharacterNode* temp = current;
            current = current->m_next;
            delete temp;
            m_stringLength--;

        } else {
            prev = current;
            current = current->m_next;

        }
    }
}