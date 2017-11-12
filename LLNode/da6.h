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
using std::cout;
using std::endl;
#include <functional>
#include <utility>
//using std::size_t;

// reverseList() function
// This reverses a list
// Pre:
//		TODO!!
template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType>> & head) {
	//print_list(head);
	if (head != nullptr) {

		shared_ptr<LLNode2<ValType>> current = head;
		shared_ptr<LLNode2<ValType>> next;
		shared_ptr<LLNode2<ValType>> prev = nullptr;

		while (current != nullptr) {

			next = current->_next;
			current->_next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	return;
}


////////////////////////////////////////
// Class LLMap                        //
////////////////////////////////////////

// Class LLMap
// 
// Invariants:
//		TODO

template<typename KeyType, typename ValType>
class LLMap {
private:
	using KVTYPE = std::pair<KeyType, ValType>;
	shared_ptr<LLNode2<KVTYPE>> _list;

public:

	// LLMap() Constructor
	// 
	// Pre:
	//		None.
	LLMap():_list(nullptr)
	{}

	// Size() function
	// fdas
	// Pre:
	//		None.
	size_t size() {
		auto temp = _list;
		if(temp == nullptr) return 0;

		size_t count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->_next;
		}
		return count;
	}

	size_t size() const {
		auto temp = _list;

		if(temp == nullptr) return 0;

		size_t count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->_next;
		}
		return count;
	}

	bool empty() {
		return _list == nullptr;
	}

	bool empty() const {
		return _list == nullptr;
	}

	ValType* find(const KeyType & key) {
		auto currPos = _list;

		while(currPos) {
			if(currPos->_data.first == key) {
				return &(currPos->_data.second);
			}
			currPos = currPos->_next;
		}
		
		return nullptr;
	}

	const ValType* find(const KeyType & key) const {
		auto currPos = _list;

		while(currPos) {
			if(currPos->_data.first == key) {
				return &(currPos->_data.second);
			}
			currPos = currPos->_next;
		}
		
		return nullptr;
	}

	void insert(const KeyType & key, const ValType & val) {

		if(!_list) {
			_list = make_shared<LLNode2<std::pair<KeyType,ValType>>>(std::make_pair(key,val));
		}
		else {
			_list->_next = make_shared<LLNode2<std::pair<KeyType,ValType>>>(std::make_pair(key,val));
		}
	}

	void erase(const KeyType & key) {
		auto temp = _list;
		if(temp->_data.first == key) {
			_list = _list->_next;
			return;
		}
		while(temp->_next) {
			if(temp->_next->_data.first == key) {
				temp->_next = temp->_next->_next;
				return;
			}
			temp = temp->_next;
		}
	}

	void traverse(std::function<void(KeyType, ValType)> function) {
		shared_ptr<LLNode2<std::pair<KeyType,ValType>>> currPos = _list;
		while(currPos) {
			function(currPos->_data.first,currPos->_data.second);
			currPos = currPos->_next;
		}
	}

public:
	// BIG FIVE
	~LLMap() = default;
	LLMap(const LLMap & rhs) = delete;
	LLMap(LLMap && rhs) = delete;
	LLMap operator=(const LLMap & rhs) = delete;
	LLMap operator=(LLMap && rhs) = delete;
};
#endif
