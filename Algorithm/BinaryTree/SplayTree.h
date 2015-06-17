#ifndef _SPLAYTREE_
#define _SPLAYTREE_
#include <iostream>
using namespace std;
template <typename Comparable>
class SplayTree
{
private:
	struct SplayNode
	{
		Comparable element;
		SplayNode *left;
		SplayNode *right;
		SplayNode *parent;
		SplayNode(const Comparable & ele, SplayNode *lc, SplayNode *rc, SplayNode *p)  //不能用字面常量值初始化一个非常量引用。 因此这里使用常量引用
		:element(ele), left(lc), right(rc), parent(p){}
		SplayNode(Comparable && ele, SplayNode *lc, SplayNode *rc, SplayNode *p)
		:element(std::move(ele)), left(lc), right(rc), parent(p){}
	};
	SplayNode *root;
	SplayNode * search(Comparable element, SplayNode * & tree)
	{
		SplayNode * result;
		if(tree == nullptr)
		{
			return nullptr;
		}
		else if( element < tree->element)
		{
			search(element, tree->left);
		}
		else if(element > tree->element)
		{
			search(element, tree->right);
		}
		else
		{

			result = tree;
			Splay(tree);
		}
		return result;
	}
	void Splay(SplayNode * & node)
	{
		if(root == nullptr)
		{
			return;
		}
		else if(node->element == root->left->element)
		{
			SingleRotateWithLeft(root);
		}
		else if(node->element == root->right->element)
		{
			SingleRotateWithRight(root);
		}
		else 
		{
			SplayNode * par;
			SplayNode * grandpa;
			par = node->parent;
			grandpa = par->parent;
			int flagi, flagj;
			flagi = (par->element < grandpa->element) ? -1 : 1;
			flagj = (node->element < par->element) ? -1 : 1;
			if(flagi==-1 && flagj==-1)
			{
				LeftZig_Zig(node);
			}
			else if(flagi==-1 && flagj==1)
			{
				LeftZig_Zag(node);
			}
			else if(flagi==1 && flagj==-1)
			{
				RightZig_Zag(node);
			}
			else if(flagi==1 && flagj==-1)
			{
				RightZig_Zig(node);
			}
		}
	}
	void SingleRotateWithLeft(SplayNode * & k2)
	{
		SplayNode * k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		//k1->parent = k2->parent;
		k2 = k1;
	}
	void SingleRotateWithRight(SplayNode * & k2)
	{
		SplayNode * k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;

		k2 = k1;
	}

	void DoubleRotateWithLeft(SplayNode * & k3)
	{
		SingleRotateWithRight(k3->left);
		SingleRotateWithLeft(k3);
	}
	void DoubleRotateWithRight(SplayNode * & k3)
	{
		SingleRotateWithLeft(k3->right);
		SingleRotateWithRight(k3);
	}

	void LeftZig_Zig(SplayNode * & x)
	{
		SplayNode * par;
		SplayNode * grandpa;
		par = x->parent;
		grandpa = par->parent;
		SingleRotateWithLeft(par);
		SingleRotateWithLeft(grandpa);
		SingleRotateWithLeft(grandpa->right);
	}
	void RightZig_Zig(SplayNode * & x)
	{
		SplayNode * par;
		SplayNode * grandpa;
		par = x->parent;
		grandpa = par->parent;
		SingleRotateWithRight(par);
		SingleRotateWithRight(grandpa);
		SingleRotateWithRight(grandpa->left);
	}
	void LeftZig_Zag(SplayNode * & x)
	{
		DoubleRotateWithLeft(x->parent->parent);
	}
	void RightZig_Zag(SplayNode * & x)
	{
		DoubleRotateWithRight(x->parent->parent);
	}
};
#endif