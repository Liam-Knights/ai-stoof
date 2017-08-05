#pragma once
#include "BehaveNode.h"
#include "dyna.h"


class ComppositeNode : public BehaveNode
{
public:
	/*
		virtual destructor
		deletes any children made by behave node or any other class
	*/
	virtual ~ComppositeNode()
	{
		for (unsigned int i = 0; i < children.Size(); i++)
		{
			delete children[i];
		}
	}
	dynamArray<BehaveNode*> children;
	BehaveNode* m_PendingNode = nullptr;
};