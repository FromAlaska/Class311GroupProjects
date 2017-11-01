#ifndef FILE_TSSARRAY_H
#define FILE_TSSARRAY_H

#include <cstddef>
#include <algorithm>
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
	//static const int DEFAULT_CAP = 16;

/*
 * Public functions
 */
public:

//BIG 5

	//DEFAULT CTOR & CTOR FROM SIZE
	explicit TSSArray(size_type size = size_type(0)) :_capacity(size), _size(size), _data(new value_type[_capacity])
	{}

	//COPY CTOR
	TSSArray(const TSSArray & rhs):_capacity(rhs._capacity),_size(rhs._size), _data(rhs._data) {
		std::copy(rhs.begin(), rhs.end(), begin());
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
	}

	//COPY ASSIGNMENT
	TSSArray & operator=(const TSSArray & rhs){
		_capacity = rhs._capacity;
		_size = rhs._size;
		_data = rhs._data;
		return *this;
	} 

	//MOVE ASSIGNMENT NO THROW
	TSSArray & operator=(TSSArray && rhs) noexcept {
		swap(rhs);
		return *this;
	}

//MEMBER OPERATOR FUNCTIONS

	//OPERATOR[]
	value_type & operator[](size_type size) {
		return _data[size];
	}
	//CONST OPERATOR[]
	value_type & operator[](size_type size) const {
		return _data[size];
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
			TSSArray<T> newarray(2 * size);
			for (std::size_t i = 0; i < size; i++)
			{
				newarray[i] = _data[i];
			}
			newarray._size = size;
			swap(newarray);
		}
	}

	iterator insert(iterator i, const value_type & v) {
		return i;
	}

	iterator erase(iterator i) {
		return i;
	}

	iterator begin() {
		return _data;
	}

	iterator begin() const {
		return _data;
	}

	iterator end() {
		return begin() + size();
	}

	iterator end() const {
		return begin() + size();
	}

	void push_back(const value_type & v) {

		//_size += 1;
		///*if (_capacity > _size) {
		//_data[_size] = v;
		//}
		//else {
		//resize(_size);
		//}*/
		//resize(_size);
		//_data[_size] = v;

	}

	void pop_back() {
		
	}

	void swap(TSSArray<T> & rhs) noexcept {
		/*std::swap(rhs._capacity, _capacity);
		std::swap(rhs._size, _size);
		std::swap(rhs._data, _data);*/
	}


};



#endif
