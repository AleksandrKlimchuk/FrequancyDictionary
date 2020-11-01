#include "text_handler.hpp"

void handleText(std::string& text)
{
  eraseIncorrectSymbol(text);
  transformHighToLowCase(text);
}