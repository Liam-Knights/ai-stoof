#pragma once
#include "entity.h"


class entity;
class BaseDecision
{
public:
	virtual void DecisionMaking(entity* pEntity, float fDeltaTime)= 0;
};