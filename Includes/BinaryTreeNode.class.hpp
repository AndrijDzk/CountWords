#pragma once

#include <string>

class BinaryTreeNode
{
public:
					BinaryTreeNode(std::string const &Key, size_t Value, BinaryTreeNode* Parent, BinaryTreeNode* Left, BinaryTreeNode* Right);
	static void		Add(BinaryTreeNode** Root, std::string const &Key);
	void			Print() const;
					~BinaryTreeNode();

private:
	std::string		Key;
	size_t			Value;
	BinaryTreeNode*	Parent;
	BinaryTreeNode*	Left;
	BinaryTreeNode*	Right;
};