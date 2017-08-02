#pragma once
#include "Agent.h"

class StateMachine;

class AI3 : public Agent
{
public:
	AI3();
	virtual ~AI3();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* Render);

private:
	StateMachine* m_pStateMachine;
};

