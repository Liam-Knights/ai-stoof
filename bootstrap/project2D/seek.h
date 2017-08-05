#pragma once
#include "IBehaviour.h"

class seek : public IBehaviour
{
public:

	/*
	constructor for seek class
	basically here for fWeighting
	*/
	seek(float fWeighting);

	/*
	destructor
	defualt
	*/
	virtual ~seek();

	/*
	calculate for seek
	gets the mouse position
	calculates the direction and velocity
	then returns velocity
	*/
	Vector2 calculate(Agent* pAgent, float fDeltaTime);
};

