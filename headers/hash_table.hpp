#ifndef HASH_TABLE_001
#define HASH_TABLE_001

#include "linked_list.hpp"

class HashTable
{
public:
  HashTable(size_t capacity = 256);
  HashTable(const HashTable&);
  HashTable(HashTable&&) noexcept;

  HashTable& operator=(const HashTable&);
  HashTable& operator=(HashTable&&) noexcept;

  ~HashTable();

  void rehash();

  void insert(const word_t&);
  void remove(const std::string&);
  word_t& search(const std::string&) const;

  word_t* makeArrayFromHashTable() const;
  size_t getSize() const;
private:
  LinkedList* lists_;
  size_t size_;
  size_t capacity_;

  size_t getHash(const std::string&) const;
  size_t getIndex(size_t hash, size_t size) const;
};

#endif
