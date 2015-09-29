#ifndef _AVLTREE_
#define _AVLTREE_
#include "BinarySearchTree.h"
#include <cmath>
#include <iostream>
using namespace std;

static const int ALLOWED_IMBLANCE = 1;
template <typename Comparable>
class AVL_Tree 
{
public:
//	AVL_Tree()
private:
	struct AvlNode
	{
		Comparable element;
		AvlNode *left;
		AvlNode *right;
		int      height;

		AvlNode(const Comparable & ele, AvlNode *lt, AvlNode *rt, int h=0)
		:element(ele), left(lt), right(rt), height(h){}
		AvlNode(Comparable && ele, AvlNode *lt, AvlNode *rt, int h=0)
		:element(std::move(ele)), left(lt), right(rt), height(h){}
	};
//	int height;

	int Height(AvlNode *t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	void insert(const Comparable & x, AvlNode * & t)
	{
		if(t == nullptr)
		{
			t = new AvlNode(x, nullptr, nullptr);
		}
		else if(x < t->element)
		{
			insert(x, t->left);
		}
		else if(x > t->element)
		{
			insert(x, t->right);
		}

		blance(t);
	}

/**
*Assume t is balanced or within one of being balanced
*/
	void blance(AvlNode * & t)
	{
		if(t==nullptr)
			return;
		if(Height(t->left) - Height(t->right) > ALLOWED_IMBLANCE)
		{
			if(Height(t->left->left) >= Height(t->left->right))
			{
				SingleRotateWithLeft(t);
			}
			else
			{
				DoubleRotateWithLeft(t);
			}
		}
		else if(Height(t->right) - Height(t->left) > ALLOWED_IMBLANCE)
		{
			if(Height(t->right->right) >= Height(t->right->left))
			{
				SingleRotateWithRight(t);
			}
			else
			{
				DoubleRotateWithRight(t);
			}
		}

		t->height = max(Height(t->left), Height(t->right)) + 1;
	}
	/**
	*Rotate binary tree node with left child
	*For AVL trees, this is single rotation for case 1
	*Update heights, then set new root
	*/
	void SingleRotateWithLeft(AvlNode * & k2)
	{
		AvlNode *k1;
		k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(Height(k2->left), Height(k2->right)) + 1;
		k1->height = max(Height(k1->left), Height(k1->right)) + 1;
		k2 = k1;
	}
	/**
	*Rotate binary tree node with left child
	*For AVL trees, this is single rotation for case 4
	*Update heights, then set new root
	*/
	void SingleRotateWithRight(AvlNode * & k2)
	{
		AvlNode *k1;
		k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height = max(Height(k2->left), Height(k2->right)) + 1;
		k1->height = max(Height(k1->left), Height(k1->right)) + 1;
		k2 = k1;
	}

	/**
	*Double rotate binary tree node: first left child
	*with its right child; then node k3 with new left child
	*For AVL trees, this is a double rotation for case2
	*Update heights, then set new root
	*/
	void DoubleRotateWithLeft(AvlNode * & k3)
	{
		SingleRotateWithRight(k3->left);
		SingleRotateWithLeft(k3);
	}
	/**
	*Double rotate binary tree node: first right child
	*with its right child; then node k3 with new right child
	*For AVL trees, this is a double rotation for case3
	*Update heights, then set new root
	*/
	void DoubleRotateWithRight(AvlNode * & k3)
	{
		SingleRotateWithLeft(k3->right);
		SingleRotateWithRight(k3);
	}
};
#endif