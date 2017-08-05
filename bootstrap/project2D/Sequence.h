#pragma once
#include "CompositeNode.h"

class Sequence : public ComppositeNode
{
	/*
		Execute function
		for loop that returns the e-bhaviour failure if execute is exactly equal
		if not return success
	*/
	BehaveiourResult Execute()
	{
		for (unsigned int i = 0; i < children.Size(); ++i)
		{
			if (children[i]->Execute() == EBHAVIOUR_FAILURE)
			{
				return EBHAVIOUR_FAILURE;
			}
		}
		return EBEHAVIOUR_SUCCESS;
	}
};