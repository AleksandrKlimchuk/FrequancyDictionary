#include <iostream>
#include <fstream>
#include "text_handler.hpp"
#include "frequancy_dictionary.hpp"

int main(int argc, char** argv)
{
  try
  {
    std::string inputFileName, outputFileName = "Frequancy_dictionary_for_", out = "The_most_popular_words_for_";

    std::cout << "Enter name of input file: ";
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
      std::cerr << "Input file can't be open\n";
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
      std::cerr << "Output file can't be open.\n";
      return -2;
    }
  }
  catch (const std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return -3;
  }
  return 0;
}


