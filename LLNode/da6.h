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
	using _dummy = shared_ptr<LLNode2<KVTYPE>>;

public:

	LLMap()  //_dummy(nullptr)
	{}

	int size() {
		return 1; // TODO
	}
	int size() const {
		return 1; // TODO
	}

	bool empty() {
		return true; // TODO
	}
	bool empty() const {
		return true;
	}
	
	ValType* find(const KeyType & key) {
		return nullptr;
		// TODO
	}

	const ValType* find(const KeyType & list) const {
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