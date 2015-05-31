#include "BinarySearchTree.h"

/**
*	return true if X is found 
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& X) const
{
	return contains(X, root);
}

/**
*	Insert X into the tree; duplicates are ignored
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & X)
{
	insert(X. root);
}
/**
*	Insert X into the tree by move; duplicates are ignored
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && X)
{
	insert(std::move(X). root);
}
/**
*	remove X from the tree
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & X)
{
	remove(X, root);
}
/**
*	makeEmpty()
*	make the tree an empty tree
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}
/**
*	Constructor
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{

}
/**
*	~BinarySearchTree()
*	Destructor
*/
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}
/**
*	Copy Constructor
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree<Comparable> & rsh)
{
	root = clone(rsh.root);
}
/**
*	move Constructor
*/
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree<Comparable> && rsh)
{
	root = clone(rsh.root);
}
/**
*	拷贝赋值运算符
*/
template<typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable> & rsh)
{
	if(this != &rsh)
	{
		BinarySearchTree temp(rsh);
		makeEmpty(root);
		root = temp.root;
	}
	return *this;
}
/**
*	移动赋值运算符
*/
template<typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=( BinarySearchTree<Comparable> && rsh)
{
	if(this != &rsh)
	{
		makeEmpty(root);
		root = rsh.root;
		rsh.root = nullptr;
	}
	return *this;
}



int main()
{
//	BinarySearchTree<int> tree;

	return 0;
}