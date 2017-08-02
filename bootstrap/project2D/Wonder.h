#pragma once
#include "IBehaviour.h"

class Wonder : public IBehaviour
{
public:
	Wonder(float fWeighting);
	virtual ~Wonder();

	Vector2 calculate(Agent* pAgent, float fDeltaTime);
	Vector2 setAngle(Vector2 Value, int Vect);
private:
	int WonderAngle;
};

