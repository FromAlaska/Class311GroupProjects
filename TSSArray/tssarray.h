#ifndef FILE_TSSARRAY_H
#define FILE_TSSARRAY_H

#include <cstddef>
#include <algorithm>
#include <iostream>
using std::max;


// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of int, allocated with new[], owned by
//      *this, holding _capacity ints. Exception: _data may be nullptr,
//      if _capacity == 0.



template<typename T>
class TSSArray
{
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
	//static const size_type DEFAULT_CAP = 16;

/*
 * Public functions
 */
public:

//BIG 5

	//DEFAULT CTOR & CTOR FROM SIZE
	explicit TSSArray(size_type size = size_type(0))
		:_capacity(std::max(size, size_type(16))),
		// _capacity must be declared before _data
		_size(size),
		_data(new value_type[_capacity])
	{}
	


	//COPY CTOR
	TSSArray(const TSSArray & rhs) :_capacity(rhs._capacity), _size(rhs._size), _data(new value_type[_capacity]) {

		try {
			std::copy(rhs.begin(), rhs.end(), begin());
		}
		catch (...) {
			delete[] _data;
			throw;
		}
	}

	//MOVE CTOR
	TSSArray(TSSArray && rhs) noexcept :_capacity(rhs._capacity),_size(rhs._size), _data(rhs._data) {
		rhs._capacity = 0;
		rhs._size = 0;
		rhs._data = nullptr;
	}

	//DCTOR NO THROW
	~TSSArray() {
		delete[] _data;
		//delete iterator;
	}

	//COPY ASSIGNMENT
	TSSArray & operator=(const TSSArray & rhs){
		TSSArray temp(rhs);
		swap(temp);
		return *this;
	} 

	//MOVE ASSIGNMENT NO THROW
	TSSArray & operator=(TSSArray && rhs) noexcept {
		swap(rhs);
		return *this;
	}

//MEMBER OPERATOR FUNCTIONS

	//OPERATOR[]
	value_type & operator[](size_type index) {
		return _data[index];
	}
	//CONST OPERATOR[]
	value_type & operator[](size_type index) const {
		return _data[index];
	}

//GENERAL OPERATOR FUNCTIONS

	size_type size() const {
		return _size;
	}

	bool empty() const {
		return size() == size_type(0);
		//return true;
	}

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
	

	iterator insert(iterator i, const value_type & v) {
		
		auto index = i - begin();

		
		if (_capacity < _size+1)
		{
			resize(_size+1);
		}
		

		for (size_type ii = index; ii != _size-1; ii++)
		{
			std::swap(_data[ii], _data[ii+1]);
		}
		
		if (i == end())
		{
			_data[_size-1] = v;
		}
		else
			_data[index] = v;

		_size++;
		return i;
		
	}

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

	iterator begin() {
		return _data;
	}

	const_iterator begin() const {
		return _data;
	}

	iterator end() {
		return begin() + size();
	}

	const_iterator end() const {
		return begin() + size();
	}

	void push_back(const value_type & v) {

		_size++;
		if (_capacity <= _size) {
			resize(_size);
		}
		_data[_size-1] = v;
	
	}

	void pop_back() {

		_size--;
	}

	void swap(TSSArray<T> & rhs) noexcept {
		std::swap(_capacity, rhs._capacity);
		std::swap(_size, rhs._size);
		std::swap(_data, rhs._data);
	}


};



#endif
