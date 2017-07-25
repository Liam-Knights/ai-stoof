#pragma once
#include "CompositeNode.h"

class Selecter : public ComppositeNode
{
	BehaveiourResult Execute()
	{




		BehaveNode* child = m_PendingNode;

		unsigned int i = -1;
		if (!child)
		{
			i = 0;
		}


		for (; i < children.Size(); ++i)
		{

			if (i >= 0)
			{
				child = children[i];
			}
			BehaveiourResult result = child->Execute();
			
			if (result == EBEHAVIOUR_SUCCESS)
			{
				m_PendingNode = nullptr;
				return EBEHAVIOUR_SUCCESS;
			}

			if (result == EBEHAVIOUR_PENDING)
			{
				m_PendingNode = child;
				return EBEHAVIOUR_PENDING;
			}
		}

		m_PendingNode = nullptr;
		return EBHAVIOUR_FAILURE;
	}
};