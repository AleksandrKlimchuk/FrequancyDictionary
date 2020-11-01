#include "text_handler.hpp"

void eraseIncorrectSymbol(std::string& text)
{
  for (int i = 0; i < text.length(); i++)
  {
    if (!isLetter(text[i]) && text[i] != ' ' && text[i] != '-')
    {
      if (i != 0 && isLetter(text[i - 1]) && (i + 1) < text.length() && isLetter(text[i + 1]))
      {
        text[i] = ' ';
      }
      else
      {
        text.erase(i, 1);
        --i;
      }
    }
    else
    {
      if (isLetter(text[i]) && i + 1 == text.length())
      {
        text += ' ';
      }
      if (text[i] == ' ')
      {
        size_t j;
        if (i > 0 && text[i - 1] == ' ')
        {
          j = i;
        }
        else
        {
          j = i + 1;
        }
        while (text[j] == ' ' && j < text.length())
        {
          text.erase(j, 1);
        }
      }
    }
  }
}