#include "BinaryTreeNode.class.hpp"
#include <iostream>
#include <cstddef>

			BinaryTreeNode::BinaryTreeNode(
				std::string const &Key, size_t Value,
				BinaryTreeNode *Parent,
				BinaryTreeNode *Left, BinaryTreeNode *Right
				) :
					Key(Key),
					Value(Value),
					Parent(Parent),
					Left(Left),
					Right(Right) {}

BinaryTreeNode::~BinaryTreeNode()
{
	if (this->Left)
		delete this->Left;
	if (this->Right)
		delete this->Right;
}

void		BinaryTreeNode::Add(BinaryTreeNode** Root,
				std::string const &Key)
{
	int					compare;
	BinaryTreeNode*		Parent = NULL;

	while (Root && *Root && (compare = (*Root)->Key.compare(Key)))
	{
		if (compare < 0)
		{
			Parent = *Root;
			Root = &((*Root)->Left);
		}
		else
		{
			Parent = *Root;
			Root = &((*Root)->Right);
		}
	}
	if (Root && *Root)
		(*Root)->Value++;
	else if (Root)
		(*Root) = new BinaryTreeNode(Key, 1, Parent, NULL, NULL);
}

void BinaryTreeNode::Print() const
{
	if (this->Right)
		this->Right->Print();
	std::cout << this->Key << ' ' << this->Value << std::endl;
	if (this->Left)
		this->Left->Print();
}
