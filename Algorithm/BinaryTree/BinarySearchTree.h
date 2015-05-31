#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;
//typedef int Comparable;
template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree & rhs);  //拷贝构造函数
	BinarySearchTree(const BinarySearchTree && rhs); //移动构造函数
	~BinarySearchTree();

	const Comparable & findMin() const;
	const Comparable & findMax() const;
	bool contains(const Comparable & X) const;
	bool isEmpty() const;
	void makeEmpty();
	void insert(const Comparable & X);
	void insert(Comparable && X);  //?????????插入右值
	void remove(const Comparable & X);
	BinarySearchTree & operator=(const BinarySearchTree & rhs); //拷贝赋值运算符
	BinarySearchTree & operator=(BinarySearchTree && rhs); //移动赋值运算符

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const Comparable & c, BinaryNode* l, BinaryNode* r)
				: element(c), left(l), right(r){}
		BinaryNode(Comparable && c, BinaryNode* l, BinaryNode* r)
				: element(std::move(c)), left(l), right(r){}
	};
	BinaryNode* root;

	void insert(const Comparable & X, BinaryNode* & t);
	void insert(Comparable && X, BinaryNode* & t);
	void remove(const Comparable & X, BinaryNode* & t);
	BinaryNode* findMin(BinaryNode* & t) const;
	BinaryNode* findMax(BinaryNode* & t) const;
	bool contains(const Comparable & X, BinaryNode* t) const;
	void makeEmpty(BinaryNode* & t);
	void printTree(BinaryNode* & t, ostream & out) const;
	BinaryNode* clone(BinaryNode* & t) const;
	BinaryNode* clone(BinaryNode* && t) const;

};

/*************************private methods***********************************/
/**
*	if X in the tree, return true, else return false
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & X, BinaryNode* t) const
{
	if(t == nullptr)
	{
		return false;
	}
	else if(X < t->element)
	{
		contains(X, t->left);
	}
	else if(X > t->element)
	{
		contains(X, t->right);
	}
	else
	{
		return true;
	}
}
/**
*	find the minimum element in the tree 
*	为什么函数名前面要加一个 typename ???
*	前面加一个typename 意在说明 BinarySearchTree<Comparable>::BinaryNode 是一个类型，具体请见C++Primer P593
*/
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* & t) const
{
	if(t == nullptr)
	{
		return nullptr;
	}
	else if(t->left == nullptr) 
	{
		return t;
	}
	else
	{
		return findMin(t->left);
	}
}


/**
*	find the maxmum element in the tree
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* & t) const
{
	if(t == nullptr)
	{
		return nullptr;
	}
	
	while(t->right != nullptr)
	{
		t = t-right;
	}
	return t;	
}

/*
*	insert X into the tree, if X already exits in the tree t, do nothing, else do it!
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & X, BinaryNode * & t)
{
	if(t == nullptr)
	{
		*t = new BinaryNode(X, nullptr, nullptr);
	}
	else if(X > t->element)
	{
		insert(X, t-right);
	}
	else if(X < t->element)
	{
		insert(X, t->left);
	}
}
/*
*	insert X into the tree by move, if X already exits in the tree t, do nothing, else do it!
*/
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && X, BinaryNode * & t)
{
	if(t == nullptr)
	{
		*t = new BinaryNode(std::move(X), nullptr, nullptr);
	}
	else if(X > t->element)
	{
		insert(std::move(X), t-right);
	}
	else if(X < t->element)
	{
		insert(std::move(X), t->left);
	}
}

/**
*	remove X from the tree t
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& X, BinaryNode* & t)
{
	if(t == nullptr)
		return;
	else if(X < t->element)
	{
		remove(X, t->left);
	}
	else if(X > t->element)
	{
		remove(X, t->right);
	}
	else if(t->left != nullptr && t->right != nullptr)
	{
		BinaryNode* p=findMin(t->right);
		t->element = p->element;
		remove(p->element, t->right);
	}
	else
	{
		BinaryNode* old_node = t;
		t = (t->left != nullptr)? t->left : t->right;
		delete old_node;
	}
	// else if(t->left != nullptr)
	// {
	// 	t->element = t->left->element;
	// 	delete t->left;
	// }
	// else if(t->right!= nullptr)
	// {
	// 	t->element = t->right->element;
	// 	delete t->right;
	// }
}

/**
*	makeEmpty()
*	make a tree node an empty node
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode* & t)
{
	if(t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	else
		return;
}
/**
*	clone
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode* & t) const
{
	if(t == nullptr)
		return nullptr;
	else
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
}
/**
*	clone by move
*/
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode* && t) const
{
	if(t == nullptr)
		return nullptr;
	else
		return new BinaryNode(std::move(t->element), clone(t->left), clone(t->right));
}
#endif