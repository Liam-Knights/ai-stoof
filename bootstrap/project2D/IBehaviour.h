#pragma once
#include "Vector2.h"
class Agent;

class IBehaviour
{
public:

	/*
	constructor for IBehaviour class
	basically here for fWeighting just like pursue, seek, flee and wonder
	*/
	IBehaviour(float fWeighting)
	{
		m_fWeighting = fWeighting;
	}

	/*
		virtual calculate function
		kinda just a base class
	*/
	virtual Vector2 calculate(Agent* pAgent, float fDeltaTime) = 0;
	float m_fWeighting;

};