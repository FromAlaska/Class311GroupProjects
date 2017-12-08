// treesort.h  INCOMPLETE
// Glenn G. Chappell
// 15 Nov 2017
//
// For CS 311 Fall 2017
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <type_traits>
using std::remove_reference;
#include <algorithm>
using std::stable_sort;
using std::copy;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;
#include <memory>
using std::shared_ptr;
using std::make_shared;

template<typename Ndata>
struct BST {
	Ndata _data;
	shared_ptr<BST<Ndata>> _left;
	shared_ptr<BST<Ndata>> _right;
	BST(Ndata& item):_data(item), _left(nullptr),_right(nullptr){}

	~BST(){}
};

template<typename Ndata>
void insert(shared_ptr<BST<Ndata>> & head, Ndata & key)
{
	if (!head)
	{
		head = make_shared<BST<Ndata>>(key);
	}

	if(key < head->_data)
	{
		if(head->_left)
		{
			insert(head->_left,key);
		}
		else
		{
			head->_left = make_shared<BST<Ndata>>(key);
			return;
		}
	}

	else
	{
		if(head->_right)
		{
			insert(head->_right,key);
		}
		else
		{
			head->_right = make_shared<BST<Ndata>>(key);
			return;
		}
	}
}

template<typename Ndata>
void traverse(shared_ptr<BST<Ndata>> head, Ndata & it) {
}

// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	if(first == last) return;
	// Get the type that FDIter points to
	using Value = typename remove_reference<decltype(*first)>::type;
	shared_ptr<BST<FDIter>> head;

	FDIter temp = first;

	for(FDIter iter = first; iter != last; ++iter)
	{
		insert(head,temp);
	}

  // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS. BUT IT DOES
  // NOT MEET THE REQUIREMENTS OF THE ASSIGNMENT.
 /* vector<Value> buff(distance(first, last));
  copy(first, last, buff.begin());
  stable_sort(buff.begin(), buff.end());
  copy(buff.begin(), buff.end(), first);*/

}

#endif //#ifndef FILE_TREESORT_H_INCLUDED
