#pragma once

enum BehaveiourResult
{
	
	EBHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS
};

class BehaveNode
{
public:
	virtual BehaveiourResult Execute() = 0;
};