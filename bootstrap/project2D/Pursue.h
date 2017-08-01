#pragma once
#include "IBehaviour.h"
#include "AU.h"


class Pursue :public IBehaviour
{
public:
	Pursue(float fWeighting);
	virtual ~Pursue();

	Vector2 calculate(Agent* pAgent, float fDeltaTime);

	void setTarget(Agent* Target);

private:
	Agent* m_pAI;

};

