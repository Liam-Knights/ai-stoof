#pragma once
#include "State.h"
#include "Pursue.h"

class StatePursue : public State
{
public:

	/*
	state purse constructor
	sets m_pursue to a new Pursue
	pushes the the new pursue
	*/
	StatePursue();

	/*
	destructor
	for loop that deletes the new pursue made in the constructor
	*/
	~StatePursue();

	//onenter
	void OnEnter(StateMachine* pMachine);

	/*
	on update function
	this decides both the speed and velocity
	it then sets the position of the pursueing agent
	*/
	void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent);

	// draw
	void OnDraw(Renderer2D* m_2dRenderer);

	//on exit
	void OnExit(StateMachine* pMachine);

	/*
	set target function
	sets m_pPurse as the target Agent
	*/
	void setTarget(Agent* Target);

private:
	Pursue* m_pPursue;
};

