#include "Pursue.h"
#include "Agent.h"

/*
	constructor for pursue class
	basically here for fWeighting
*/
Pursue::Pursue(float fWeighting) : IBehaviour(fWeighting)
{
}

/*
	destructor
	defualt
*/
Pursue::~Pursue()
{
}

/*
	calculate for pursue
	gets the position of the agent that follows the mouse
	calculates the direction and velocity
	then returns the velocity calculation
*/
Vector2 Pursue::calculate(Agent* pAgent, float fDeltaTime)
{
	Vector2 target = m_pAI->getPos() + m_pAI->getVeloc();

	Vector2 v2Dir = target - pAgent->getPos();

	v2Dir.normalise();



	return v2Dir * 50.0f * fDeltaTime;
}

/*
	set target function for pursue
	sets target as the agent that follows the mouse
*/
void Pursue::setTarget(Agent* Target)
{
	
	m_pAI = Target;
	
		
}