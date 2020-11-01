#include "text_handler.hpp"


bool isLetter(char letter)
{
  int code = int(letter);
  return ((code >= ENGLISH_LETTERS_HIGH_BEGIN_CODE && code <= ENGLISH_LETTERS_HIGH_END_CODE)
    || (code >= ENGLISH_LETTERS_LOW_BEGIN_CODE && code <= ENGLISH_LETTERS_LOW_END_CODE)
    || (code >= RUSSIAN_LETTERS_BEGIN_CODE && code <= RUSSIAN_LETTERS_END_CODE)
    || (code >= NUMS_BEGIN_CODE && code <= NUMS_END_CODE) || letter == '¸' || letter == '¨');
}