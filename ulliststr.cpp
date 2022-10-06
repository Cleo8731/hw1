#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}


/***********************
  WRITE YOUR CODE HERE
***********************/

void ULListStr::push_back(const std::string& val)
{
  if (empty()) { // no items yet
    head_ = new Item();
    tail_ = head_;
  }
  else if (tail_->last == ARRSIZE) { // if tail item has no space at end
    Item* temp = new Item();
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
  }
  size_++;
  tail_->val[tail_->last] = val;
  tail_->last++;
}

void ULListStr::pop_back()
{
  if (!empty()) {
    if (tail_->last - tail_->first == 1) {
      // delete item
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
      if (size_ > 1) tail_->next = NULL; // perhaps unnecessary
    }
    else {
      tail_->val[tail_->last - 1] = ""; 
      tail_->last--;
    }
    size_--;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if (empty()) { // no items yet
    head_ = new Item();
    tail_ = head_;
    // difference with push_back: reassign first last
    head_->first = head_->last = ARRSIZE;
  }
  else if (head_->first == 0) { // if head item has no space at beginning
    head_->prev = new Item();
    head_->prev->next = head_;
    head_ = head_->prev;
    // difference with push_back: reassign first last
    head_->first = head_->last = ARRSIZE;
  }
  size_++;
  head_->first--;
  head_->val[head_->first] = val;
}

void ULListStr::pop_front()
{
  if (!empty()) {
    if (head_->last - head_->first == 1) {
      // delete item
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
      if (size_ > 1) head_->prev = NULL; // perhaps unnecessary
    }
    else {
      head_->val[head_->first] = ""; 
      head_->first++;
    }
    size_--;
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t index = head_->first + loc;
  size_t itemNum = index/ARRSIZE;
  Item *it = head_;
  for (size_t i = 0; i < itemNum; i++) 
  {
    it = it->next;
  }
  return &(it->val[index % ARRSIZE]);
}

/***********************
          STOP
***********************/


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}