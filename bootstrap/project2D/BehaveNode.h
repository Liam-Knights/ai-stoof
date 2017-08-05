#pragma once

/*
	enum to decide if failed or success
	pending placed in for later use never ended up being used
*/
enum BehaveiourResult
{
	
	EBHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

/*
	bas class for behaveiour classes
*/
class BehaveNode
{
public:

	/*
		destructor for Behave node
		virtual 
	*/
	virtual ~BehaveNode() {};

	/*
		execute function
		virtual
	*/
	virtual BehaveiourResult Execute() = 0;
};