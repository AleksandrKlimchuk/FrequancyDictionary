#include <iostream>
#include <fstream>
#include "text_handler.hpp"
#include "frequancy_dictionary.hpp"

void eraseIncorrectSymbol(std::string&);
void transformHighToLowCase(std::string&);

const int SIZE_OF_HASH_TABLE = 256;

int main()
{
  setlocale(LC_ALL, "Russian");
  std::string inputFileName, outputFileName = "Frequancy_dictionary_for_", out = "The_most_popular_words_for_";

  std::cout << "Введите название файла с исходными данными: ";
  std::cin >> inputFileName;
  outputFileName += inputFileName;
  out += inputFileName;

  std::ifstream inFile(inputFileName + ".txt");

  FrequancyDictionary dictionary;

  if (inFile.is_open())
  {
    while (!inFile.eof())
    {
      std::string newLine;
      std::getline(inFile, newLine);
      handleText(newLine);
      for (int i = 0; i < newLine.length(); i++)
      {
        if (newLine[i] != ' ')
        {
          size_t j = newLine.find(' ', i);
          std::string newWord = newLine.substr(i, j);
          dictionary.add(newWord);
          newLine.erase(i, j);
          i = -1;
        }
      }
    }
  }
  else
  {
    std::cerr << "Файл с исходными данными не может быть открыт.\n";
    return -1;
  }

  std::ofstream outFile(outputFileName + ".txt");
  std::ofstream outFile2(out + ".txt");
  if (outFile.is_open() && outFile2.is_open())
  {
    dictionary.printInFile(outFile);
    dictionary.printTheMostPopularWords(outFile2);
  }
  else
  {
    std::cerr << "Файл для вывода словаря не может быть открыт.\n";
    return -1;
  }
  return 0;
}


