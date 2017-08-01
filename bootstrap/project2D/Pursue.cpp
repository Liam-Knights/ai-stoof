#include "Pursue.h"
#include "Agent.h"


Pursue::Pursue(float fWeighting) : IBehaviour(fWeighting)
{
}


Pursue::~Pursue()
{
}

Vector2 Pursue::calculate(Agent* pAgent, float fDeltaTime)
{
	Vector2 target = m_pAI->getPos() + m_pAI->getVeloc();

	Vector2 v2Dir = target - pAgent->getPos();

	v2Dir.normalise();



	return v2Dir * 50.0f * fDeltaTime;
}

void Pursue::setTarget(Agent* Target)
{
	
	m_pAI = Target;
	
		
}