#include <string>

const int ENGLISH_LETTERS_HIGH_BEGIN_CODE = 65;
const int ENGLISH_LETTERS_HIGH_END_CODE = 90;
const int ENGLISH_LETTERS_LOW_BEGIN_CODE = 97;
const int ENGLISH_LETTERS_LOW_END_CODE = 122;
const int RUSSIAN_LETTERS_BEGIN_CODE = -64;
const int RUSSIAN_LETTERS_END_CODE = -1;
const int RUSSIAN_LETTERS_LOW_BEGIN_CODE = -32;
const int NUMS_BEGIN_CODE = 48;
const int NUMS_END_CODE = 57;

bool isLetter(char letter);
void eraseIncorrectSymbol(std::string& text);
void transformHighToLowCase(std::string& text);
void handleText(std::string& text);