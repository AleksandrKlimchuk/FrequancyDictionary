#ifndef DICTIONARY_001
#define DECTIONARY_001

#include <string>
#include "hash_table.hpp"

class FrequancyDictionary
{
public:
  FrequancyDictionary();
  void add(const std::string& word);
  std::string& search(const std::string&) const;
  void printInFile(std::ostream& outFile)const;
  void printTheMostPopularWords(std::ostream& outFile) const;
private:
  HashTable hashTable_;
};

#endif
