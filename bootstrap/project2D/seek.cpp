#include "seek.h"
#include "Input.h"
#include "Agent.h"

using namespace aie;

/*
	constructor for seek class
	basically here for fWeighting
*/
seek::seek(float fWeighting) : IBehaviour(fWeighting)
{
}

/*
	destructor
	defualt
*/
seek::~seek()
{
}

/*
	calculate for seek
	gets the mouse position
	calculates the direction and velocity
	then returns velocity
*/
Vector2 seek::calculate(Agent* pAgent, float fDeltaTime)
{
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2  v2MousePos(nMouseX, nMouseY);

	
	Vector2 v2Dir = v2MousePos - pAgent->getPos();

	v2Dir.normalise();

	Vector2 v2Veloc = v2Dir * 100.0f * fDeltaTime;

	return v2Veloc;
}