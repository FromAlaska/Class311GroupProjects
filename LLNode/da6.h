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
void reverseList(shared_ptr<LLNode2<ValType>> & head) {
	//print_list(head);
	if (head != nullptr) {
		shared_ptr<LLNode2<ValType> > current = head, next, prev = nullptr;

		while (current!=nullptr)
		{
			next = current->_next;
			current->_next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}
}

template<typename KeyType, typename ValType>
class LLMap {
private:
	using KVTYPE = std::pair<KeyType, ValType>;
	shared_ptr<LLNode2<KVTYPE>> _list;

public:

	LLMap():_list(nullptr){

	}

	int size() const {
		size_t n = 0;
		while (_list->_next != nullptr) {
			n++;
		}
		return n;
	}

	bool empty() {
		return size() < 1;
	}

	bool empty() const {
		return size() < 1;
	}

	ValType* find(const KeyType & key) {
		shared_ptr<LLNode2<KVTYPE>> currPos;
		for(currPos = _list; currPos; currPos = currPos->_next) {
	  		if(currPos->_data.first == key)
				return &(currPos->_data.second);
	 	}
		return nullptr;
	}

	const ValType* find(const KeyType & key) const {
		shared_ptr<LLNode2<KVTYPE>> currPos;
		for(currPos = _list; currPos; currPos = currPos->_next) {
	  		if(currPos->_data.first == key)
	    		return &(currPos->_data.second);
	 	}
		return nullptr;
	}

	void insert(const KeyType & key, const ValType & val) {

		// shared_ptr<LLNode2<KVTYPE>> insert;
		// KVTYPE _inserted = std::make_pair(key, val);
		// insert->_data = _inserted;
		// insert->_next = _head;
		// _head = insert;

	}

	void erase(const KeyType & key) {
		// shared_ptr<LLNode2<KVTYPE>> temp = _head;
		// shared_ptr<LLNode2<KVTYPE>> oldTemp = _head;
        //
		// // if the list only contains one node and its the key
		// if (_head->_data.first == key)
		// {
		// 	head = nullptr;
		// }
        //
		// // see if the item is in the linked list
		// while (temp->_next!= nullptr)
		// {
		// 	oldTemp = temp;
		// 	temp = temp->_next;
		// 	if (temp->_data.first == key)
		// 	{
		// 		oldTemp->_next = temp->_next;
		// 		temp->_next = nullptr;
		// 	}
        //
		// }

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
