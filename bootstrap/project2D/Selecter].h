#pragma once
#include "CompositeNode.h"

class Selecter : public ComppositeNode
{
	BehaveiourResult execute()
	{
		for (unsigned int i = 0; children.Size(); ++i)
		{
			if (children[i]->Execute() == EBEHAVIOUR_SUCCESS)
			{
				return EBEHAVIOUR_SUCCESS;
			}
		}
		return EBHAVIOUR_FAILURE;
	}
};