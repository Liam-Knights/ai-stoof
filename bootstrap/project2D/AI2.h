#pragma once
#include "Agent.h"
#include "StatePursue.h"
class StateMachine;

class AI2 : public Agent
{
public:

	/*
	AI constructor
	creates new state machine
	creates new stateMove
	adds State move to the stateMachine
	pushes the state
	*/
	AI2();

	/*
	AI destructor
	Virtual
	*/
	virtual ~AI2();

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

	/*
	set target function
	sets target to pursue
	*/
	void setTarget(Agent* Target);

private:
	StateMachine* m_pStateMachine;
	StatePursue* m_pStatePursue;
	

};

