#pragma once
#include "DecisionQestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:
	DecisionButtonPressed();
	virtual ~DecisionButtonPressed();

	void DecisionMaking(entity* pEntity, float fDeltaTime);
};

