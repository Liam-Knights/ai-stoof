#include "flee.h"
#include "Agent.h"


/*
	constructor for flee class
	basically here for fWeighting
*/
flee::flee(float fWeighting) : IBehaviour(fWeighting)
{
}

/*
	destructor
	defualt
*/
flee::~flee()
{
}

/*
	calculate for flee
	getts the position 200, 200
	calculates the direction to not go near it
	then returns the calculation for velocity
*/
Vector2 flee::calculate(Agent* pAgent, float fDeltaTime)
{
	
	Vector2  v2fleePos(200.0f, 200.0f);


	Vector2 v2Dir =pAgent->getPos() - v2fleePos;

	float fMag = v2Dir.magnitude();
	v2Dir.normalise();

	float DistScale = (fMag / 200);
	if (DistScale > 1.0f)
	{
		DistScale = 1.0f;
	}

	m_fWeighting = 1.0f - DistScale;

	return v2Dir * 100.0f * fDeltaTime;
}