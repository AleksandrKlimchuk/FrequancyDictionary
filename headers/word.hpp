#ifndef WORD_TYPE_001
#define WORD_TYPE_001

#include <ostream>
#include <string>
#include <iostream>

struct word_t
{
  std::string word = "";
  size_t frequency = 1;

  bool operator<(const word_t& word) const
  {
    return (this->frequency < word.frequency);
  }

  bool operator<=(const word_t& word) const
  {
    return (this->frequency <= word.frequency);
  }

  bool operator>(const word_t& word) const
  {
    return (this->frequency > word.frequency);
  }

  bool operator>=(const word_t& word) const
  {
    return (this->frequency >= word.frequency);
  }

  bool operator==(const word_t& word) const
  {
    return (this->frequency == word.frequency);
  }

  bool operator!=(const word_t& word) const
  {
    return (this->frequency != word.frequency);
  }

  friend std::ostream& operator<<(std::ostream& out, word_t& word)
  {
    return (out << word.word << ": " << word.frequency << " repeats.\n");
  }
};

#endif
