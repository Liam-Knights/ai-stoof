#pragma once
#include "State.h"


class StateWonder : public State
{
public:
	StateWonder();
	~StateWonder();

	//on enter
	void OnEnter(StateMachine* pMachine);

	//on update
	void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent);

	// draw
	void OnDraw(Renderer2D* m_2dRenderer);

	//on exit
	void OnExit(StateMachine* pMachine);
};

