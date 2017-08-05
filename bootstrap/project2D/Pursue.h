#pragma once
#include "IBehaviour.h"
#include "AU.h"


class Pursue :public IBehaviour
{
public:
	
	/*
	constructor for pursue class
	basically here for fWeighting
	*/
	Pursue(float fWeighting);

	/*
	destructor
	defualt
	*/
	virtual ~Pursue();

	/*
	calculate for pursue
	gets the position of the agent that follows the mouse
	calculates the direction and velocity
	then returns the velocity calculation
	*/
	Vector2 calculate(Agent* pAgent, float fDeltaTime);

	/*
	set target function for pursue
	sets target as the agent that follows the mouse
	*/
	void setTarget(Agent* Target);

private:
	Agent* m_pAI;

};

