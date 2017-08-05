#pragma once
#include "IBehaviour.h"

class Wonder : public IBehaviour
{
public:

	/*
	this should probably be named wander
	constructor for wonder
	sets the angle for wonder
	*/
	Wonder(float fWeighting);

	/*
	defualt destructor
	*/
	virtual ~Wonder();

	/*
	wonders calculate function
	CIRCLE_DIST and CIRCLE_RAD in defines.h

	creates a vector 2 for circle center and the gets its velocity
	creates a displacement and then multiplies it by CIRCLE_RAD
	*/
	Vector2 calculate(Agent* pAgent, float fDeltaTime);

	/*
	setAngle function

	sets the x and y
	then returns the vector 2 known as result
	*/
	Vector2 setAngle(Vector2 Value, int Vect);
private:
	int WonderAngle;
};

