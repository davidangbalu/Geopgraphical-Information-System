#pragma once
#include "City.h"

class TreeNode
{
	friend class BST;
public:
	TreeNode(City city);
	~TreeNode();
	bool isLeaf() const;
private:
	City city;
	TreeNode* leftptr;
	TreeNode* rightptr;
};