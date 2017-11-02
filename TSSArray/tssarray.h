// Jim Samson
// Cameron Titus
// Samuel Grenon
// tssarray.h
// This is for Assignment 5

#ifndef FILE_TSSARRAY_H 
#define FILE_TSSARRAY_H

#include <cstddef>
#include <algorithm>
#include <iostream>
using std::max;

// *****************************
// Class TSSArray
// *****************************
//
// This class is a "smarter" array class compared with KSArray. It's not quite as good
// as std::vector, but it is significantly better than KSArray.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of int, allocated with new[], owned by
//      *this, holding _capacity ints. Exception: _data may be nullptr,
//      if _capacity == 0.

template<typename T>
class TSSArray {

//TSSARRAY TYPES

/*
 * Public variables
 */
public:
	
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type*;
	using const_iterator = const value_type *;

/*
 * Private data members
 */
private:

	size_type _capacity;
	size_type _size;
	value_type *_data;
	static const size_type DEFAULT_CAP = 16;

/*
 * Public functions
 */
public:

// BIG 5
	// DEFAULT CTOR & CTOR FROM SIZE
	// Constructs an array of size 16 by default. It also constructs an array size from the constructor.
	// Pre:
	// 	none.
	explicit TSSArray(size_type size = size_type(0))
							:_capacity(std::max(size, size_type(DEFAULT_CAP))),
							// _capacity must be declared before _data
							_size(size),
							_data(new value_type[_capacity])
							{}
	// COPY CTOR
	// Copies the values from an old object to a new object
	// Pre:
	// 	none.
	TSSArray(const TSSArray & rhs) :_capacity(rhs._capacity), _size(rhs._size), _data(new value_type[_capacity]) {

		try {
			std::copy(rhs.begin(), rhs.end(), begin());
		}
		catch (...) {
			delete[] _data;
			throw;
		}
	}

	// MOVE CTOR
	// Moves all the values from an old oject to another object, then "deletes" the old object.
	// Pre:
	// 	none.
	TSSArray(TSSArray && rhs) noexcept :_capacity(rhs._capacity),_size(rhs._size), _data(rhs._data) {
		rhs._capacity = 0;
		rhs._size = 0;
		rhs._data = nullptr;
	}

	// DCTOR NO THROW
	// This frees any dynamically allocated memory
	// Pre:
	// 	none.
	~TSSArray() {
		delete[] _data;	
	}

	// COPY ASSIGNMENT
	// Copies all the values from the old object to the new object.
	// Pre:
	// 	none.
	TSSArray & operator=(const TSSArray & rhs){
		TSSArray temp(rhs);
		swap(temp);
		return *this;
	} 

	// MOVE ASSIGNMENT NO THROW
	// Moves all the values from the old object to another object.
	// Pre:
	// 	none.
	TSSArray & operator=(TSSArray && rhs) noexcept {
		swap(rhs);
		return *this;
	}

// MEMBER OPERATOR FUNCTIONS

	// OPERATOR[]
	// Creates an array using the index size.
	// Pre:
	// 	index must not be negative.
	value_type & operator[](size_type index) {
		return _data[index];
	}
	// CONST OPERATOR[]
	// Creates an array using the index size.
	// Pre:
	// 	index must not be negative.
	value_type & operator[](size_type index) const {
		return _data[index];
	}

// GENERAL OPERATOR FUNCTIONS

	// size() function
	// Returns the size of the array.
	// Pre:
	// 	none.
	size_type size() const {
		return _size;
	}

	// empty() function
	// Returns a flag if the array is empty or not.
	// Pre:
	// 	none.
	bool empty() const {
		return size() == size_type(0);	
	}

	// resize() function
	// Resizes the array, while maintaining old values of all data items and the new array.
	// Pre:
	// 	none.
	void resize(size_type size) {

		if (_capacity >= size) {

			_size = size;
		}
		else {
			
			size_type newCapacity;
			iterator newData;
			newCapacity = size * 2;
			newData = new value_type[newCapacity];
			try {
				std::copy(begin(), end(), newData);
			}
			catch (...)
			{
				delete[] newData;
				throw;
			}
			delete[] _data;
			_data = newData;
			_capacity = newCapacity;
			_size = size;	
		}
	}
	
	// insert() function
	// Inserts the data item just before that that referenced by the iterator.
	// Pre:
	// 	none.
	iterator insert(iterator i, const value_type & v) {
		
		size_type index = i - begin();
		resize(_size+1);
		
        
		for (size_type ii = _size -1; ii > index; ii--){
			_data[ii] = _data[ii-1];
		}
		
		if (i == end()){
			_data[_size-1] = v;
		}
		else
			_data[index] = v;
        
		return begin() + index;
		
	}

	// erase() function
	// Removes the item referenced by the iterator. Then returns to the item after the removed item.
	// Pre:
	// 	none.
	iterator erase(iterator i) {
		auto index = i - begin();
		if (i == end())
		{
			return end();
		}

		for (size_type ii = index; ii != _size - 1; ii++)
		{
			std::swap(_data[ii], _data[ii + 1]);
		}
		_size--;
		return i;
	}

	// begin() function
	// Returns the iterator at item 0 in the array.
	// Pre:
	// 	none.
	iterator begin() {
		return _data;
	}

	// begin() const function
	// Returns the iterator at item 0 in the array.
	// Pre:
	// 	none.
	const_iterator begin() const {
		return _data;
	}

	// end() function
	// Returns the iterator to one-past the end of the array.
	// Pre:
	// 	none.
	iterator end() {
		return begin() + size();
	}

	// end() const function
	// Returns the iterator to one-past the end of the array.
	// Pre:
	// 	none.
	const_iterator end() const {
		return begin() + size();
	}

	// Push_back() function
	// Adds the item to the end of the array, while increasing the array by 1.
	// Pre:
	// 	none.
	void push_back(const value_type & v) {

		_size++;
		if (_capacity <= _size) {
			resize(_size);
		}
		_data[_size-1] = v;
	
	}

	// pop_back() function
	// Removes the last item from the array.
	// Pre: 
	// 	none.
	void pop_back() {

		_size--;
	}

	// swap() function
	// Swaps the values of two objects.
	// Pre:
	// 	none.
	void swap(TSSArray<T> & rhs) noexcept {
		std::swap(_capacity, rhs._capacity);
		std::swap(_size, rhs._size);
		std::swap(_data, rhs._data);
	}
};

#endif
