#pragma once
#include "entity.h"


class entity;

/*
	base class
*/
class BaseDecision
{
public:

	/*
		decision making for base dicision
		virtual
	*/
	virtual void DecisionMaking(entity* pEntity, float fDeltaTime)= 0;
};