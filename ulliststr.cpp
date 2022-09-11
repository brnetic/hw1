#include <cstddef>
#include <iostream>
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

void ULListStr::push_back(const std::string& val){
	if (empty()){
		head_ = new Item;
		head_->val[4] = val;
		head_->first = 4;
		tail_ = head_;
		tail_->last = 5;
		
	}
	else if(tail_->last<ARRSIZE){
		tail_->last++;
		tail_->val[tail_->last-1] = val;
	}
	else{
		tail_->last = ARRSIZE-1;
		tail_->next = new Item;
		tail_->next->prev = tail_;
		tail_ = tail_->next;
		tail_->val[0] = val;
		tail_->last = 1;
	}
	size_++;
}
void ULListStr::push_front(const std::string& val){
	if (empty()){
		head_ = new Item;
		head_->val[4] = val;
		head_->first = 4;
		tail_ = head_;
		tail_->last = 5;
		//head_->next = head_->prev = NULL;		
	}
	else if(head_->first > 0){
		head_->first--;
		head_->val[head_->first] = val;

	}
	else{
		head_->first = 0;
		head_->prev = new Item;
		head_->prev->next = head_;
		head_ = head_->prev;
		head_->val[ARRSIZE-1] = val;
		head_->first = ARRSIZE-1;
	}
	size_++;
}
void ULListStr::pop_back(){
	if(tail_->last > 0){
		tail_->last--;
	}
	else{
		Item *temp = tail_;
		tail_ = tail_->prev;
		tail_->next = NULL;
		delete temp;
	}
	size_--;
}
void ULListStr::pop_front(){
	if(head_->first < ARRSIZE){
		head_->first++;
	}
	else{
		Item *temp = head_;
		head_ = head_->next;
		head_->prev = NULL;
		delete temp;
	}
	size_--;
}
std::string const & ULListStr::front() const{
	return head_->val[head_->first];
}
std::string const & ULListStr::back() const{
	return tail_->val[tail_->last-1];
}
std::string* ULListStr:: getValAtLoc(size_t loc) const{
	int loc1 = head_->first;
	if(loc >+ size()-1){
		return NULL;
	}
	Item *s = head_;
	for(unsigned int i = 0;i<loc;i++){
		loc1++;
		if(loc1>9){
			loc1 = 0;
			s = s->next;
		}
	}
	return &(s->val[loc1]);
}