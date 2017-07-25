#pragma once
#include "BehaveNode.h"
#include "dyna.h"


class ComppositeNode : public BehaveNode
{
public:
	dynamArray<BehaveNode*> children;
};