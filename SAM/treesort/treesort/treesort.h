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





template<typename Ndata>
struct BST {
	Ndata _data;
	shared_ptr<Ndata> left;
	shared_ptr<Ndata> right;
	BST(Ndata item, shared_ptr<Ndata>_left, shared_ptr<Ndata> _right);
		
	
	~BST(){}


	void insert(shared_ptr<BST<Ndata>> &, Ndata);
	void traverse(shared_ptr<BST<Ndata> > head, Ndata & it);


};

template<typename Ndata>
void BST<Ndata>::insert(shared_ptr<BST<Ndata> > & head, Ndata key) {

	if (head == NULL) {
		head->_data = key;
	}

	if (key < head->_data) {
		p->left = insert(p->left, key);
	}

	else if (key > head->_data) {
		head->right = insert(head->right, key);
	}
}

template<typename Ndata>
void BST<Ndata>::traverse(shared_ptr<BST<Ndata> > head, Ndata & it) {

	if (p = NULL) {
		return;
	}
	if (head->left != NULL) {
		traverse(head->left, it)
	}

	*it++ = head->_data;

	if (left->right != NULL) {
		traverse(head->right, it)
	}
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
    // Get the type that FDIter points to
    using Value = typename remove_reference<decltype(*first)>::type;
	

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS. BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE ASSIGNMENT.
   /* vector<Value> buff(distance(first, last));
    copy(first, last, buff.begin());
    stable_sort(buff.begin(), buff.end());
    copy(buff.begin(), buff.end(), first);*/


}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

