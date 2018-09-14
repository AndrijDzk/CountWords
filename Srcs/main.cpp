#include "BinaryTreeNode.class.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

const char*		delimiters = " \n\t";

int main(int argc, char **argv)
{
	char				buff;
	BinaryTreeNode*		Tree = NULL;
	std::string			word;

	if (argc > 1)
	{
		std::fstream	text(argv[1], std::fstream::in);

		if (text.good())
		{
			while (text.read(&buff, 1).good())
			{
				if (strchr(delimiters, buff))
				{
					if (!word.empty())
					{
						BinaryTreeNode::Add(&Tree, word);
						word.clear();
					}
				}
				else
					word.push_back(buff);
			}
			if (!word.empty())
			{
				BinaryTreeNode::Add(&Tree, word);
				word.clear();
			}
			if (Tree)
			{
				Tree->Print();
				delete Tree;
			}
		}
	}
    return 0;
}