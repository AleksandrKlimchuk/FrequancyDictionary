#ifndef DICTIONARY_001
#define DECTIONARY_001

#include <string>
#include "hash_table.hpp"

class FrequancyDictionary
{
public:
  FrequancyDictionary();
  void add(const std::string& word);
  std::string& search(const std::string& word) const;
  void printInFile(std::ofstream& outFile);
private:
  HashTable hashTable_;
};

#endif
