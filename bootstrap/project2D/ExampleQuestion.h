#pragma once
#include "BehaveNode.h"
#include "Input.h"

using namespace aie;
class ExampleQuestion : public BehaveNode
{
public:
	BehaveiourResult Execute()
	{
		/*
		Execute function
		gets the keybored key Q and if pressed
		return success
		if not return failure
		*/
		
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