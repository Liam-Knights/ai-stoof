#pragma once
#include "BaseDecision.h"
class DecisionNothingPressed : public BaseDecision
{
public:

	/*
	constructor for Decision nothing pressed
	*/
	DecisionNothingPressed();

	/*
	destructor for decision nothing pressed
	Virtual
	*/
	virtual ~DecisionNothingPressed();

	/*
	dicision making function for dicision nothing pressed
	clears the screen
	prints out cat
	*/
	void DecisionMaking(entity* pEntity, float fDeltaTime);
};

