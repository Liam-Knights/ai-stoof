#pragma once

enum BehaveiourResult
{
	
	EBHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

class BehaveNode
{
public:
	virtual ~BehaveNode() {};
	virtual BehaveiourResult Execute() = 0;
};