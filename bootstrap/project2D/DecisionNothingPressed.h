#pragma once
#include "BaseDecision.h"
class DecisionNothingPressed : public BaseDecision
{
public:
	DecisionNothingPressed();
	virtual ~DecisionNothingPressed();
	void DecisionMaking(entity* pEntity, float fDeltaTime);
};

