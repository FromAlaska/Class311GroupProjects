// treesort.h  
// Samuel Grenon
// Cameron K. Titus
// Jim Samson
// 19 Nov 2017
// For CS 311 Fall 2017
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <type_traits>
using std::remove_reference;
#include <memory>
using std::shared_ptr;
using std::make_shared;


/*
struct BSTNode
This struct creates a node of type Ndata. A node contains one Ndata type and two
children.
Invariants: All nodes within the tree must have the same Ndata type.
*/
template<typename Ndata>
struct BSTNode {
	Ndata _data;
	shared_ptr<BSTNode<Ndata>> _left;
	shared_ptr<BSTNode<Ndata>> _right;
	
	//Three Parameter Constructor
	//Preconditions - none
	//Exception Neutral
	explicit BSTNode(Ndata item) : _left(nullptr), _right(nullptr), _data(item) 
	{}

	~BSTNode() = default;

};

/*
struct TheTree
This struct creates a Binary Search tree filled with BSTNodes. It also contains
functions that allow us to insert new nodes, and traverse it.
Invariants: All nodes must have the same type Val.
*/
template<typename Val>
struct TheTree {
	using Node = BSTNode<Val>;
	shared_ptr<Node> rootNode = nullptr;

	//insert(Val val)
	//Returns a Node shared pointer. First checks to see if the root is null
	//then sifts down checking to see if the right and the left child or either null
	//or less then val.
	//Pre condition: none
	//No Throw guarantee
	shared_ptr < Node > insert(Val val) noexcept {
		if (rootNode == nullptr) {
			rootNode = make_shared<Node>(val);
			return rootNode;
		}

		shared_ptr<Node> parent = rootNode;
		while (true) {
			if (val < parent->_data) {
				if (parent->_left != nullptr) {
					parent = parent->_left;
				}
				else {
					break;
				}
			}
			else {
				if (parent->_right != nullptr) {
					parent = parent->_right;
				}
				else {
					break;
				}
			}
		}
		auto newNode = make_shared<Node>(val);
		if (val < parent->_data) {
			parent->_left = newNode;
		}
		else {
			parent->_right = newNode;
		}
		return newNode;
	}

};

// createlist
// Recursive function that does an inorder sort.
// Pre condition: Should only be called with treesort or itself.
// No Throw Guarantee
template<typename FDIter, typename Node>
FDIter createList(FDIter iter, Node node) noexcept {
	if (node->_left != nullptr) {
		iter = createList(iter, node->_left);
	}
	*iter = node->_data;
	iter++;
	if (node->_right != nullptr) {
		iter = createList(iter, node->_right);
	}
	return iter;
}


//Treesort
//Sorts a given range using treesort.
//Pre condition: Must have valid iterators.
//Exception Neutral
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	
	if (first == last) {
		return;
	}
	using value = typename remove_reference<decltype(*first)>::type;	
	using Node = BSTNode<value>;
	auto aTree = new TheTree<value>;
	for (FDIter iter = first; iter != last; iter++) {
		aTree->insert(*iter);
	}
	createList(first, aTree->rootNode);
	delete aTree;
	
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED