#ifndef CharacterNODE_H
#define CharacterNODE_H

class CharacterNode {

public:
    char m_data;
    CharacterNode* m_next;

    CharacterNode(char character) : m_data(character), m_next(nullptr) {}

};

#endif

//for the sake of convenience I decided not to use getters and setter for this class as I felt it made the code in
//my SLLString class needlessly complicated looking. However, I understand it is the convention to use
//getters and setters, so I have provided an example CharacterNode Class below using getters and setter so show
//my understanding of what a class with them would look like.

/*class CharacterNode {
 *
 *public:
 *  CharacterNode(char tempData) {
 *      m_data = tempData;
 *      m_next = nullptr;
 *  }
 *
 *  char getData() { return m_data; }
 *  void setData(char tempData) { m_data = tempData; }
 *
 *  CharacterNode* getnext() { return m_next; }
 *  void setNext(CharacterNode* tempNext) { m_next = tempNext; }
 *
 *private:
 *   char m_data;
 *   CharacterNode* m_next;
 *
 *};
 */