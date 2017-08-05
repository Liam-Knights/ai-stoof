#pragma once
#include "BaseDecision.h"

class DecisionQuestion : public BaseDecision
{
public:

	/*
		decision making function
		virtual
	*/
	virtual void DecisionMaking(entity* pEntity, float fDeltaTime) = 0;


	BaseDecision* m_pTrueDecision;
	BaseDecision* m_pFalseDecision;
};
