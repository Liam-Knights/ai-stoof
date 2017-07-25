#pragma once
#include "BehaveNode.h"
#include "Input.h"

using namespace aie;
class ExampleAction : public BehaveNode
{
public:
	BehaveiourResult Execute()
	{
		
		if (Input::getInstance()->isKeyDown(INPUT_KEY_Q))
		{
			return EBEHAVIOUR_SUCCESS;
		}
		else
		{
			return EBHAVIOUR_FAILURE;
		}
	}
};