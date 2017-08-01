#pragma once
#include "State.h"
#include "Pursue.h"

class StatePursue :
	public State
{
public:
	StatePursue();
	~StatePursue();

	//onenter
	void OnEnter(StateMachine* pMachine);

	//on update
	void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent);

	// draw
	void OnDraw(Renderer2D* m_2dRenderer);

	//on exit
	void OnExit(StateMachine* pMachine);

	void setTarget(Agent* Target);

private:
	Pursue* m_pPursue;
};

