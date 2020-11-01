#include "linked_list.hpp"

LinkedList::LinkedList() :
  head_(nullptr),
  tail_(nullptr),
  size_(0)
{}

LinkedList::~LinkedList()
{
  while (head_)
  {
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

LinkedList::LinkedList(const LinkedList& copy)
{
  head_ = nullptr;
  tail_ = nullptr;
  size_ = copy.size_;
  Node* temp = copy.head_;
  while (temp)
  {
    Node* newNode = new Node;
    newNode->data = temp->data;
    newNode->next = nullptr;
    if (!this->head_)
    {
      this->head_ = newNode;
    }
    else
    {
      this->tail_->next = newNode;
    }
    this->tail_ = newNode;
    temp = temp->next;
  }
}

LinkedList::LinkedList(LinkedList&& copy) noexcept
{
  this->head_ = copy.head_;
  this->tail_ = copy.tail_;
  this->size_ = copy.size_;
  copy.head_ = nullptr;
  copy.tail_ = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& copy)
{
  if (this == &copy)
  {
    return *this;
  }
  LinkedList temp(copy);
  this->head_ = temp.head_;
  this->tail_ = temp.tail_;
  this->size_ = temp.size_;
  temp.head_ = nullptr;
  temp.tail_ = nullptr;
  return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& copy) noexcept
{
  this->head_ = copy.head_;
  this->tail_ = copy.tail_;
  this->size_ = copy.size_;
  copy.head_ = nullptr;
  copy.tail_ = nullptr;
  return *this;
}

bool LinkedList::isEmpty() const
{
  return (!this->head_);
}

bool LinkedList::insert(const word_t& word)
{
  Node* temp = searchNodeByKey(word.word);
  if (temp)
  {
    temp->data.frequency++;
    return false;
  }
  else
  {
    temp = new Node{ word };
    if (isEmpty())
    {
      this->head_ = temp;
    }
    else
    {
      this->tail_->next = temp;
      temp->prev = this->tail_;
    }
    this->tail_ = temp;
    this->size_++;
    return true;
  }
}

LinkedList::Node* LinkedList::searchNodeByKey(const std::string& str) const
{
  Node* temp = this->head_;
  while (temp && temp->data.word != str)
  {
    temp = temp->next;
  }
  return temp;
}

word_t& LinkedList::searchByKey(const std::string& str) const
{
  Node* temp = searchNodeByKey(str);
  if (temp)
    return temp->data;
  else
  {
    throw std::invalid_argument("There is no word with such key.");
  }
}

void LinkedList::deleteByKey(const std::string& str)
{
  Node* temp = searchNodeByKey(str);
  if (temp)
  {
    if (temp->prev)
    {
      temp->prev->next = temp->next;
    }
    if (temp->next)
    {
      temp->next->prev = temp->prev;
    }
    if (temp == head_)
    {
      head_ = head_->next;
    }
    if (temp == tail_)
    {
      tail_ = tail_->prev;
    }
    --this->size_;
    delete temp;
  }
  else
  {
    throw std::invalid_argument("There is no word with such key.");
  }
}

size_t LinkedList::getSize() const
{
  return this->size_;
}

word_t* LinkedList::makeArrayFromList() const
{
  word_t* resultArray = new word_t[this->getSize()];
  Node* temp = head_;
  for (size_t i = 0; i < size_; i++, temp = temp->next)
  {
    resultArray[i] = temp->data;
  }
  return resultArray;
}