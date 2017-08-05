#include "Wonder.h"
#include "Input.h"
#include "Agent.h"
#include "Defines.h"
#include <iostream>

using namespace aie;

/*
	this should probably be named wander
	constructor for wonder
	sets the angle for wonder
*/
Wonder::Wonder(float fWeighting) : IBehaviour(fWeighting)
{
	WonderAngle = 25;
}

/*
	defualt destructor
*/
Wonder::~Wonder()
{
}

/*
	wonders calculate function 
	CIRCLE_DIST and CIRCLE_RAD in defines.h 

	creates a vector 2 for circle center and the gets its velocity
	creates a displacement and then multiplies it by CIRCLE_RAD 
*/
Vector2 Wonder::calculate(Agent* pAgent, float fDeltaTime)
{

	//center circle calculation
	Vector2 v2CircleCenter = pAgent->getVeloc();
	v2CircleCenter.normalise();

	v2CircleCenter = v2CircleCenter * CIRCLE_DIST;

	//calc the displacement
	Vector2 v2Disp(0, -1);
	v2Disp = v2Disp * CIRCLE_RAD;

	//randomely change the vector direction
	//change its angle
	v2Disp = setAngle(v2Disp, WonderAngle);
	WonderAngle += rand() % 5 - 2;
	
	Vector2 WanderForce = v2CircleCenter + v2Disp;

	return WanderForce ;
}

/*
	setAngle function

	sets the x and y
	then returns the vector 2 known as result
*/
Vector2 Wonder::setAngle(Vector2 Value, int Vect)
{
	int len = Value.magnitude();
	Vector2 Result;
	Result.x = cos(Vect) * len;
	Result.y = sin(Vect) * len;

	return Result;
}