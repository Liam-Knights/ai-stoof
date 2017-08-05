#pragma once
#include "Agent.h"

class StateMachine;

class AI3 : public Agent
{
public:

	/*
	AI constructor
	creates new state machine
	creates new stateMove
	adds State move to the stateMachine
	pushes the state
	sets x and y position
	*/
	AI3();

	/*
	AI destructor
	Virtual
	*/
	virtual ~AI3();

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

