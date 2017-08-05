#pragma once
#include "IBehaviour.h"

class flee : public IBehaviour
{
public:

	/*
	constructor for flee class
	basically here for fWeighting
	*/
	flee(float fWeighting);

	/*
	destructor
	defualt
	*/
	virtual ~flee();

	/*
	calculate for flee
	getts the position 200, 200
	calculates the direction to not go near it
	then returns the calculation for velocity
	*/
	Vector2 calculate(Agent* pAgent, float fDeltaTime);
};

