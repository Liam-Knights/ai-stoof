#pragma once
#include "Agent.h"

class StateMachine;

class AI : public Agent
{
public:
	
	/*
	AI constructor
	creates new state machine
	creates new stateMove
	adds State move to the stateMachine
	pushes the state
	*/
	AI();

	/*
	AI destructor
	Virtual
	*/
	virtual ~AI();

	/*
	update function
	calls the updates for state machine
	*/
	void Update(float fDeltaTime);

	/*
	draw function
	Draws circle
	sets the circles colour
	*/
	void Draw(Renderer2D* Render);

private:
	StateMachine* m_pStateMachine;
};

