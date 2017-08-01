#pragma once
#include "Agent.h"
#include "StatePursue.h"
class StateMachine;

class AI2 : public Agent
{
public:
	AI2();
	virtual ~AI2();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* Render);
	void setTarget(Agent* Target);

private:
	StateMachine* m_pStateMachine;
	StatePursue* m_pStatePursue;
	

};

