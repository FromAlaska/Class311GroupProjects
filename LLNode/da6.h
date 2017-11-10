// Jim Samson
// Cameron Titus
// Samuel Grenon
// November 09, 2017
//
// This is for Assignment 6
#ifndef da6_h
#define da6_h
#include "llnode2.h"
#include <cstddef>
#include <iostream>
#include <functional>
using std::size_t;

template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType> > & head) {
	//make_shared<ValType> next;
	//make_shared<ValType> prev;
	//auto current = head;

	//while (current != null) {
	//	next = current->_next;
	//	current->next = prev;
	//	prev = current;
	//	current = next;


	//}
	//head = prev
}

template<typename KeyType, typename ValType>
class LLMap {
private:
	using KVTYPE = std::pair<KeyType, ValType>;
	shared_ptr<LLNode2<KVTYPE>> _list;

public:

	LLMap(): _list(nullptr)
	{}

	int size() {
	  auto p = _list;
	  size_t n = 0;
	  while(p)
	  {
	    p = p->_next;
	    ++n;
	  }
	 return n; 
	}

	int size() const {
	  auto p = _list;
	  size_t n = 0;
	  while(p)
	  {
	   p = p->_next;
	   ++n;
	  }
	 return n;
	}

	bool empty() {
		return _list == nullptr;
	}

	bool empty() const {
		return _list == nullptr;
	}

	ValType* find(const KeyType & key) {
	 shared_ptr<LLNode2<KVTYPE>> currPos;
	 for(currPos = _list; currPos; currPos = currPos->_next) {
	  if(currPos->_data.first == key) {
	   return &(currPos->_data.second);
	  }
	 }
	 return nullptr;
	}

	const ValType* find(const KeyType & key) const {
	 shared_ptr<LLNode2<KVTYPE>> currPos;
	 for(currPos = _list; currPos; currPos = currPos->_next) {
	  if(currPos->_data.first == key) {
	    return &(currPos->_data.second);
	  }
	 }
	 return nullptr;
	}

	void insert(const KeyType & key, const ValType & val) {

	}

	void erase(const KeyType & key) {

	}

	void traverse(std::function<void(KeyType, ValType)> function) {

	}

public:
	// BIG FIVE
	~LLMap() = default;
	LLMap(const LLMap&) = delete;
	LLMap(LLMap&&) = delete;
	LLMap & operator=(const LLMap) = delete;
	LLMap & operator=(LLMap &&) = delete;
};
#endif
