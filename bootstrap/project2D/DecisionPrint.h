#pragma once
#include "BaseDecision.h"

class DecisionPrint :public BaseDecision 
{
public:
	DecisionPrint();
	virtual ~DecisionPrint();

	void DecisionMaking(entity* pEntity, float fDeltaTime);

private:
	float m_fTimer;
};
