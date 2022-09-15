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

// WRITE YOUR CODE HERE


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

void ULListStr::push_back(const std::string& val)
{
  //if there are no items in the list, then allocate new item at the point
  if(empty()){
    Item* ptr = new Item(); 
    head_ = ptr; 
    tail_ = ptr; 
    ptr->val[0] = val; 
    ptr->last++; 
  }
  else if((tail_->last) == ARRSIZE){
     Item* ptr = new Item(); 
     tail_->next = ptr; 
     ptr->prev = tail_; 
     tail_ = ptr; 
     ptr->val[0] = val;
     
  }
  else{
    tail_->val[tail_->last] = val; 
    tail_->last++; 
  }
  size_++; 
}


void ULListStr::push_front(const std::string& val){
  if(empty()){
    Item* ptr = new Item(); 
    head_ = tail_ = ptr; 
    ptr->val[0] = val; 
    ptr->last++; 
  size_++; 
  }
  else if(head_->first == 0){
    Item* ptr = new Item(); 
    ptr->next = head_;
    head_->prev = ptr; 
    head_ = ptr; 
    ptr->val[ARRSIZE-1] = val; 
    ptr->last = ARRSIZE; 
    ptr->first = ARRSIZE-1; 
    size_++; 
  }
  else{
    head_->val[head_->first-1] = val; 
    head_->first--; 
    size_++; 
  }
}

void ULListStr::pop_back(){
  if(size_ == 1){
    delete tail_; 
    tail_ = head_ =  NULL; 
  }
  else if(tail_->last == 1){
    tail_ = tail_->prev; 
    delete tail_->next; 
    tail_->next = NULL; 
  }
  //if empty 
  else if(empty()){
    return; 
    //nothing in there list empty 
  }
  else{
    tail_->last--; 
  }
  size_--; 
}

void ULListStr::pop_front(){
  //if empty 
  if(size_ == 0){
    return; 
  }
  if(size_ == 1){
    Item* ptr = head_; 
    delete ptr; 
    head_ = tail_ = NULL;  
    size_--; 
  }
  else if(head_->first == ARRSIZE-1){
    head_ = head_->next; 
    delete head_->prev; 
    head_->prev = NULL; 
    size_--; 
  }
  else{
    head_->first++; 
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
  if(loc >= size_ || loc < 0){
    return NULL; 
  }
  size_t loc_r = 0; 
  size_t temp_r = head_->first; 
  Item* ptr = head_; 
  while(loc_r != loc){
    loc_r++; 
    temp_r++; 
    if(temp_r == ptr->last){
      ptr = ptr->next; 
      temp_r = 0; 
    }
  }
  return &ptr->val[temp_r];
}
