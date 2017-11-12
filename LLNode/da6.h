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


template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType> > & head) {
	shared_ptr<LLNode2<ValType>> _prev;
	shared_ptr<LLNode2<ValType>> _current;
	shared_ptr<LLNode2<ValType>> _next;
	_current = head;

	while (_current != nullptr) {
		_next = _current->_next;
		_current->_next = _prev;
		_prev = _current;
		_current = _next;
	}
	head = _prev;
}

//******************************************
// Template class LLMap
//******************************************

//class LLMap
//LLMap holds shared_ptrs of KVTYPE which is client-specified pairs.
//Invariants:
//			_list = nullptr for an empty list. _list->_next either points to another _list
//			or points to a end of _list nullptr. 
//
//Requirements on Types:
//			LLMAP dctor must not throw

template<typename KeyType, typename ValType>
class LLMap {
private:
	using KVTYPE = std::pair<KeyType, ValType>;
	shared_ptr<LLNode2<KVTYPE>> _list;

	
public:

	//Pre: None
	//Exception Nuetral
	//No throw Guarantee
	explicit LLMap() :_list(nullptr) {

	}

	//size(const)
	//Pre - None
	//Exception Neutral
	//No-Throw Guarantee

	size_t size() const {
		shared_ptr<LLNode2<KVTYPE>> _current = _list;
		size_t n = 0;
		while (_current != nullptr) {
			n++;
			_current = _current->_next;

		}
		return n;
	}

	//empty(non const version)
	//Pre: None
	//Exception Neutral
	//No-Throw Guarantee
	bool empty() {
		return !(_list);
	}

	//empty(const version)
	//Pre: None
	//Exception Neutral
	//No-Throw Guarantee
	bool empty() const {
		return !(_list);
	}

	//Find(non const version)
	//Pre: None
	//Exception Neutral
	//Strong Gurantee
	//Will Throw if KeyType throws.

	ValType* find(const KeyType & key) {
		shared_ptr<LLNode2<KVTYPE>> _current;
		_current = _list;
		while (_current) {

			if (_current->_data.first == key) {
				return &(_current->_data.second);
			}
			_current = _current->_next;
		}
		return nullptr;
	}

	//Find(const version)
	//Pre: None
	//Exception Neutral
	//Strong Guarantee
	//Will Throw when a KeyType operation throws
	const ValType* find(const KeyType & key) const {
		shared_ptr<LLNode2<KVTYPE>> _current;
		_current = _list;
		while (_current) {

			if (_current->_data.first == key) {
				return &(_current->_data.second);
			}
			_current = _current->_next;
		}
		return nullptr;
	}

	//insert Credit goes to Duane Shaffer and his group
	//for this function. The use find() and the creation of 
	//ValType* place helped create a workable insert function.
	//Pre: None
	//Exception Neutral
	//Strong Guarantee
	//Can Throw if Find(key) Throws.
	void insert(const KeyType & key, const ValType & val) {
		ValType* place = find(key);
		if (place) {
			*place = val;
		}
		else {
			_list = make_shared<LLNode2<KVTYPE>>(std::make_pair(key, val), _list);
		}
	}

	//erase
	//Pre: None
	//Strong Guarantee
	//Throws when KeyType throws
	//Exception Neutral
	void erase(const KeyType & key) {

		if (_list->_data.first == key) {
			_list = _list->_next;
		}
		else {
			auto _current = _list;
			auto _prev = _list;
			while (_current != nullptr && _current->_data.first != key) {
				_prev = _current;
				_current = _current->_next;
			}
			_prev->_next = _current->_next; 
		}
	}

	//Pre: none
	//Basic Guarantee
	//Exception Nuetral
	void traverse(std::function<void(KeyType, ValType)> function) {
		auto _current = _list;
		while (_current!=nullptr) {
			function(_current->_data.first, _current->_data.second);
			_current = _current->_next;
		}
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
