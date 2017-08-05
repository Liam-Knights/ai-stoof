#pragma once
#include "BehaveNode.h"
#include <iostream>

class ExampleAction : public BehaveNode
{
public:
	/*
		example action constructor
		sets m_sText to text
	*/
	ExampleAction(char* text)
	{
		m_sText = text;
	}

	/*
		execute function
		prints m_sText set in constructor
		returns success
	*/
	BehaveiourResult Execute()
	{
		std::cout << m_sText << std::endl;
		return EBEHAVIOUR_SUCCESS;
	}

private:
	char* m_sText;
};