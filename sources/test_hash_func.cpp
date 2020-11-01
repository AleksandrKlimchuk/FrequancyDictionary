//#include <iostream>
//#include <fstream>
//#include "hash_table.hpp"
//#include <Windows.h>
//
//const int SIZE_OF_HASH_TABLE = 256;
//const int QUANTITY_OF_WORDS = 5000;
//
//void testInsertNewUniqueWord(std::ofstream&);
//void testInsertRepeatingWord(std::ofstream&);
//void testSearchWords(std::ofstream&);
//void testRemoveWords(std::ofstream&);
//
//int main(int, char**)
//{
//  //std::ofstream outFile("Test-hash-func.txt");
//  testInsertNewUniqueWord(outFile);
//  testInsertRepeatingWord(outFile);
//  testSearchWords(outFile);
//  testRemoveWords(outFile);
//  return 0;
//}
//
//void testInsertNewUniqueWord(std::ofstream& outputFile)
//{
//  double totalTime = 0.0;
//  size_t capacity = SIZE_OF_HASH_TABLE;
//  size_t outputIndex = 200;
//  HashTable hashTable(SIZE_OF_HASH_TABLE);
//  std::cout << "Test of insertion new unique " << QUANTITY_OF_WORDS << " words.\n";
//  if (outputFile.is_open())
//  {
//    outputFile << "Test of insetion new unique " << QUANTITY_OF_WORDS << " words.\n";
//    for (size_t i = 1; i <= QUANTITY_OF_WORDS; ++i)
//    {
//      word_t newWord = { "word" + std::to_string(i) };
//      LARGE_INTEGER time1, time2, frequency;
//      QueryPerformanceCounter(&time1);
//      hashTable.insert(newWord);
//      QueryPerformanceCounter(&time2);
//      QueryPerformanceFrequency(&frequency);
//      double time = static_cast<double>(time2.QuadPart - time1.QuadPart) / frequency.QuadPart;
//      if (i - 1 > capacity * 0.9)
//      {
//        capacity *= 2;
//      }
//      else
//      {
//        totalTime += time;
//      }
//      if (outputIndex == i)
//      {
//        std::cout << i << '\t' << std::to_string(time) << '\n';
//        outputIndex *= 2;
//      }
//      outputFile << i << '\t' << std::to_string(time) << '\n';
//    }
//    outputFile << std::endl;
//  }
//  std::cout << "Average time: ";
//  totalTime /= (QUANTITY_OF_WORDS - 5);
//  std::cout.setf(std::ios::fixed);
//  std::cout.precision(6);
//  std::cout << totalTime << "\n\n";
//}
//
//void testInsertRepeatingWord(std::ofstream& outputFile)
//{
//  double totalTime = 0.0;
//  size_t capacity = SIZE_OF_HASH_TABLE;
//  size_t outputIndex = 200;
//  HashTable hashTable(SIZE_OF_HASH_TABLE);
//  std::cout << "Test of insetion repeating " << QUANTITY_OF_WORDS << " words.\n";
//  if (outputFile.is_open())
//  {
//    outputFile << "Test of insetion repeating " << QUANTITY_OF_WORDS << " words.\n";
//    for (size_t i = 1; i <= QUANTITY_OF_WORDS; ++i)
//    {
//      word_t newWord = { "word" };
//      LARGE_INTEGER time1, time2, frequency;
//      QueryPerformanceCounter(&time1);
//      hashTable.insert(newWord);
//      QueryPerformanceCounter(&time2);
//      QueryPerformanceFrequency(&frequency);
//      double time = static_cast<double>(time2.QuadPart - time1.QuadPart) / frequency.QuadPart;
//      if (i - 1 > capacity * 0.9)
//      {
//        capacity *= 2;
//      }
//      else
//      {
//        totalTime += time;
//      }
//      if (outputIndex == i)
//      {
//        std::cout << i << '\t' << std::to_string(time) << '\n';
//        outputIndex *= 2;
//      }
//      outputFile << i << '\t' << std::to_string(time) << '\n';
//    }
//    outputFile << std::endl;
//  }
//  std::cout << "Average time: ";
//  totalTime /= (QUANTITY_OF_WORDS - 5);
//  std::cout.setf(std::ios::fixed);
//  std::cout.precision(6);
//  std::cout << totalTime << "\n\n";
//}
//
//void testSearchWords(std::ofstream& outputFile)
//{
//  double totalTime = 0.0;
//  size_t capacity = SIZE_OF_HASH_TABLE;
//  size_t outputIndex = 200;
//  HashTable hashTable(SIZE_OF_HASH_TABLE);
//  std::cout << "Test of searching " << QUANTITY_OF_WORDS << " words.\n";
//  if (outputFile.is_open())
//  {
//    outputFile << "Test of searching " << QUANTITY_OF_WORDS << " words.\n";
//    for (size_t i = 1; i <= QUANTITY_OF_WORDS; ++i)
//    {
//      word_t newWord = { "word" + std::to_string(i) };
//      hashTable.insert(newWord);
//      LARGE_INTEGER time1, time2, frequency;
//      QueryPerformanceCounter(&time1);
//      hashTable.search("word1");
//      QueryPerformanceCounter(&time2);
//      QueryPerformanceFrequency(&frequency);
//      double time = static_cast<double>(time2.QuadPart - time1.QuadPart) / frequency.QuadPart;
//      if (i - 1 > capacity * 0.9)
//      {
//        capacity *= 2;
//      }
//      else
//      {
//        totalTime += time;
//      }
//      if (outputIndex == i)
//      {
//        std::cout << i << '\t' << std::to_string(time) << '\n';
//        outputIndex *= 2;
//      }
//      outputFile << i << '\t' << std::to_string(time) << '\n';
//    }
//    outputFile << std::endl;
//  }
//  std::cout << "Average time: ";
//  totalTime /= (QUANTITY_OF_WORDS - 5);
//  std::cout.setf(std::ios::fixed);
//  std::cout.precision(6);
//  std::cout << totalTime << "\n\n";
//}
//
//void testRemoveWords(std::ofstream& outputFile)
//{
//  double totalTime = 0.0;
//  size_t capacity = SIZE_OF_HASH_TABLE;
//  size_t outputIndex = 200;
//  HashTable hashTable(SIZE_OF_HASH_TABLE);
//  std::cout << "Test of removing " << QUANTITY_OF_WORDS << " words.\n";
//  if (outputFile.is_open())
//  {
//    outputFile << "Test of removing " << QUANTITY_OF_WORDS << " words.\n";
//    for (size_t i = 1; i <= QUANTITY_OF_WORDS; ++i)
//    {
//      word_t newWord = { "word" + std::to_string(i) };
//      hashTable.insert(newWord);
//      LARGE_INTEGER time1, time2, frequency;
//      QueryPerformanceCounter(&time1);
//      hashTable.remove(newWord.word);
//      QueryPerformanceCounter(&time2);
//      QueryPerformanceFrequency(&frequency);
//      double time = static_cast<double>(time2.QuadPart - time1.QuadPart) / frequency.QuadPart;
//      hashTable.insert(newWord);
//      if (i - 1 > capacity * 0.9)
//      {
//        capacity *= 2;
//      }
//      else
//      {
//        totalTime += time;
//      }
//      if (outputIndex == i)
//      {
//        std::cout << i << '\t' << std::to_string(time) << '\n';
//        outputIndex *= 2;
//      }
//      outputFile << i << '\t' << std::to_string(time) << '\n';
//    }
//    outputFile << std::endl;
//  }
//  std::cout << "Average time: ";
//  totalTime /= (QUANTITY_OF_WORDS - 5);
//  std::cout.setf(std::ios::fixed);
//  std::cout.precision(6);
//  std::cout << totalTime << "\n\n";
//}