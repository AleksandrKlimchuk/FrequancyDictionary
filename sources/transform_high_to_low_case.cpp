#include "text_handler.hpp"

void transformHighToLowCase(std::string& text)
{
  for (int i = 0; i < text.length(); i++)
  {
    if ((int(text[i]) >= ENGLISH_LETTERS_HIGH_BEGIN_CODE && int(text[i]) <= ENGLISH_LETTERS_HIGH_END_CODE)
      || (int(text[i]) >= RUSSIAN_LETTERS_BEGIN_CODE && int(text[i]) < RUSSIAN_LETTERS_LOW_BEGIN_CODE))
    {
      text[i] = text[i] + 32;
    }
    if (text[i] == '¨')
    {
      text.at(i) = '¸';
    }
  }
}