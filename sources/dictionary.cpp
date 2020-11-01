#include "frequancy_dictionary.hpp"

const int SIZE_OF_HASH_TABLE = 256;

FrequancyDictionary::FrequancyDictionary() :
  hashTable_(SIZE_OF_HASH_TABLE)
{}

void FrequancyDictionary::add(const std::string& word)
{
  hashTable_.insert({ word, 1 });
}

size_t FrequancyDictionary::search(const std::string& word) const
{
  word_t* findedWord = hashTable_.search(word);
  if (findedWord)
  {
    return findedWord->frequncy;
  }
  else
  {
    std::cerr << "Dictionary don't contain \"" << word << "\" word";
  }
}

void FrequancyDictionary::printTheMostPopularWords(std::ostream& outFile) const
{
  word_t* dictionary = hashTable_.makeArrayFromHashTable();
  for (size_t i = 0; i < 3; i++)
  {
    outFile << i + 1 << ": " << dictionary[i];
  }
  delete[] dictionary;
}

void FrequancyDictionary::printInFile(std::ostream& outFile) const
{
  word_t* dictionary = hashTable_.makeArrayFromHashTable();
  for (size_t i = 0; i < hashTable_.getSize(); i++)
  {
    outFile << (i + 1) << ": " << dictionary[i];
  }
  delete[] dictionary;
}

