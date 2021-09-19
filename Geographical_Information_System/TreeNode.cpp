#include "TreeNode.h"


TreeNode::TreeNode(City city) : city(city), leftptr(nullptr), rightptr(nullptr)
{
}

TreeNode::~TreeNode()
{
}

bool TreeNode::isLeaf() const
{
	return (leftptr == nullptr && rightptr == nullptr);
}