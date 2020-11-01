#include "hash_table.hpp"
#include <functional>
#include <stdexcept>
#include <algorithm>

HashTable::HashTable(size_t capacity) :
  capacity_(capacity),
  size_(0)
{
  if (this->capacity_ == 0)
  {
    throw std::invalid_argument("Capacity cannot be equal 0.");
  }
  this->lists_ = new LinkedList[this->capacity_];
}

HashTable::HashTable(const HashTable& copy)
{
  this->capacity_ = copy.capacity_;
  this->size_ = copy.size_;
  this->lists_ = new LinkedList[this->capacity_];
  for (size_t i = 0; i < this->capacity_; i++)
  {
    this->lists_[i] = copy.lists_[i];
  }
}

HashTable::HashTable(HashTable&& copy) noexcept
{
  this->capacity_ = copy.capacity_;
  this->size_ = copy.size_;
  this->lists_ = copy.lists_;
  copy.lists_ = nullptr;
}

HashTable& HashTable::operator=(const HashTable& copy)
{
  if (this == &copy)
  {
    return *this;
  }
  HashTable tempHashTable(copy);
  this->capacity_ = copy.capacity_;
  this->size_ = copy.size_;
  this->lists_ = tempHashTable.lists_;
  tempHashTable.lists_ = nullptr;
  return *this;
}

HashTable& HashTable::operator=(HashTable&& copy) noexcept
{
  this->capacity_ = copy.capacity_;
  this->size_ = copy.size_;
  this->lists_ = copy.lists_;
  copy.lists_ = nullptr;
  return *this;
}

HashTable::~HashTable()
{
  delete[] lists_;
}

size_t HashTable::getHash(const std::string& str) const
{
  std::hash<std::string> hashFunction;
  size_t result = hashFunction(str);
  return result;
}

size_t HashTable::getIndex(size_t hash, size_t size) const
{
  return hash & (size - 1);
}

void HashTable::rehash()
{
  LinkedList* newList = new LinkedList[this->capacity_ * 2];
  for (size_t i = 0; i < this->capacity_; i++)
  {
    if (!(this->lists_[i].isEmpty()))
    {
      word_t* elements = this->lists_[i].makeArrayFromList();
      size_t sizeOfArray = this->lists_[i].getSize();
      for (size_t j = 0; j < sizeOfArray; j++)
      {
        size_t newIndex = getIndex(getHash(elements[j].word), capacity_ * 2);
        newList[newIndex].insert(elements[j]);
      }
      delete[] elements;
    }
  }
  delete[] this->lists_;
  this->lists_ = newList;
  newList = nullptr;
  this->capacity_ *= 2;
}

void HashTable::insert(const word_t& word)
{
  if (this->size_ > this->capacity_ * 0.9)
  {
    this->rehash();
  }
  size_t index = getIndex(getHash(word.word), this->capacity_);
  if (this->lists_[index].insert(word))
  {
    ++this->size_;
  }
}

void HashTable::remove(const std::string& str)
{
  try
  {
    size_t tempIndex = getIndex(getHash(str), this->capacity_);
    this->lists_[tempIndex].deleteByKey(str);
    --this->size_;
  }
  catch (const std::invalid_argument& exception)
  {
    throw exception;
  }
}

word_t& HashTable::search(const std::string& str) const
{
  size_t tempIndex = getIndex(getHash(str), this->capacity_);
  try
  {
    word_t& temp = this->lists_[tempIndex].searchByKey(str);
    return temp;
  }
  catch (const std::invalid_argument& exception)
  {
    throw exception;
  }
}

word_t* HashTable::makeArrayFromHashTable() const
{
  word_t* resultArray = new word_t[this->size_];
  for (int i = 0, j = 0; i < this->capacity_ && j < this->size_; ++i)
  {
    size_t tempSize = this->lists_[i].getSize();
    if (tempSize != 0)
    {
      word_t* tempArray = this->lists_[i].makeArrayFromList();
      for (size_t k = 0; k < tempSize; ++k, ++j)
      {
        resultArray[j] = tempArray[k];
      }
      delete[] tempArray;
    }
  }
  std::sort(resultArray, resultArray + size_, std::greater<word_t>());
  return resultArray;
}

size_t HashTable::getSize() const
{
  return size_;
}