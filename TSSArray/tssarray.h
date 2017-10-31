#ifndef FILE_TSSARRAY_H_INCLUDED
#define FILE_TSSARRAY_H

#include <cstddef>
using std::size_t;
#include <algorithm>
using std::max;


// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of int, allocated with new[], owned by
//      *this, holding _capacity ints. Exception: _data may be nullptr,
//      if _capacity == 0.



template<typename Val>
class TSSArray
{
//TSSARRAY TYPES
public:
	
	using value_type = Val;
	using size_type = size_t;
	using iterator = value_type*;
	using const_iterator = const value_type *;

private:
	static const size_type DEFAULT_CAP;

//BIG 5
public:
	//DEFAULT CTOR & CTOR FROM SIZE
	TSSARRAY()
	{
		DEFAULT_CAP = 16;
		_size = 0;
		_capacity = max(size, DEFAULT_CAP);
		_data = new value_type[_capacity]
	}
	explicit TSSArray(size_type size)
	{
		DEFAULT_CAP = 16;
		_capacity = max(size, DEFAULT_CAP);
		_size = size;
		_data = new value_type[_capacity];
	}

	//COPY CTOR
	TSSArray(const TSSArray & rhs)
	{}
	//MOVE CTOR
	TSSArray(TSSArray && rhs) noexcept
	{}
	//DCTOR NO THROW
	~TSSArray()
	{
		delete[] _data;
	}
	//COPY ASSIGNMENT
	TSSArray & operator=(const TSSArray & rhs)
	{} 
	//MOVE ASSIGNMENT NO THROW
	TSSArray & operator=(TSSArray && rhs) noexcept
	{}

//MEMBER OPERATOR FUNCTIONS
public:
	//OPERATOR[]
	value_type & operator[](size_type index)
	{}
	//CONST OPERATOR[]
	value_type & operator[](size_type index) const
	{}

//GENERAL OPERATOR FUNCTIONS
public:
	size_type size() const
	{
		return _size;
	}

	bool empty() const
	{
		return size() == size_type(0);
		//return true;
	}

	void resize(size_type size)
	{
		//TODO DUMMY
	}

	iterator insert(iterator i, const value_type & v)
	{
		return i;
	}

	iterator erase(iterator i)
	{
		return i;
	}

	value_type* begin()
	{
		return _data;
	}

	value_type* begin() const
	{
		return _data;
	}

	value_type* end()
	{
		return begin() + size();
	}

	value_type* end() const
	{
		return begin() + size();
	}

	void push_back(const value_type & v)
	{

	}

	void pop_back()
	{
		erase(end());
	}

	void swap(const TSSArray & rhs) noexcept {

	}



//TSSARRAY DATA MEMBERS
private:
	size_type _capacity;
	size_type _size;
	value_type *_data;

};

#endif
