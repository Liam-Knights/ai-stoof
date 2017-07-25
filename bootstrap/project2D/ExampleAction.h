#pragma once
#include "BehaveNode.h"
#include <iostream>

class ExampleAction : public BehaveNode
{
public:
	ExampleAction(char* text)
	{
		m_sText = text;
	}

	BehaveiourResult Execute()
	{
		std::cout << m_sText << std::endl;
		return EBEHAVIOUR_SUCCESS;
	}

private:
	char* m_sText;
};