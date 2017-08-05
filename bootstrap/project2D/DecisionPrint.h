#pragma once
#include "BaseDecision.h"

class DecisionPrint :public BaseDecision 
{
public:

	/*
	constructor for Decision print
	sets the timer to start at 0
	*/
	DecisionPrint();

	/*
	destructor for decision print
	Virtual
	*/
	virtual ~DecisionPrint();

	/*
	dicision making function for dicision print
	adds DelataTime to the timer
	clears the screen
	prints out how long space has been pressed
	*/
	void DecisionMaking(entity* pEntity, float fDeltaTime);

private:
	float m_fTimer;
};

