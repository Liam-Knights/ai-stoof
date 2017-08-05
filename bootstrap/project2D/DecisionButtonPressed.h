#pragma once
#include "DecisionQestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:

	/*
	constructor for decision button pressed
	*/
	DecisionButtonPressed();

	/*
	destructor for Decision button pressed
	Virtual
	*/
	virtual ~DecisionButtonPressed();

	/*
	Dicision making function
	if space is pressed run the dicision maing function from the bas class
	if not the same but m_pfalseDecion is used instead of true
	*/
	void DecisionMaking(entity* pEntity, float fDeltaTime);
};

