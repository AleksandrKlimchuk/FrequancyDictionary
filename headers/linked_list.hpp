#ifndef LINKED_LIST_001
#define LINKED_LIST_001

#include <string>
#include "word.hpp"

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  LinkedList(const LinkedList&);
  LinkedList(LinkedList&&) noexcept;
  LinkedList& operator=(const LinkedList&);
  LinkedList& operator=(LinkedList&&) noexcept;

  bool isEmpty() const;
  bool insert(const word_t&);
  word_t& searchByKey(const std::string&) const;
  void deleteByKey(const std::string&);
  word_t* makeArrayFromList() const;
  size_t getSize() const;
private:
  struct Node
  {
    word_t data;
    Node* next;
    Node* prev;
  };

  Node* head_;
  Node* tail_;
  size_t size_;

  Node* searchNodeByKey(const std::string&) const;
};

#endif
