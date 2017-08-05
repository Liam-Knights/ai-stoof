#pragma once
#include "State.h"

class StateMove : public State
{
public:

	/*
	state purse constructor
	pushes both the seek and flee behaviours
	and sets the weighting for seek to be stronger then the one for flee
	*/
	StateMove();

	/*
	destructor
	for loop that deletes the new pursue made in the constructor
	*/
	~StateMove();
	//on enter
	void OnEnter(StateMachine* pMachine);

	/*
	on update function
	this decides both the speed and velocity
	it then sets the position of the seek and flee agent which is the same agent
	*/
	void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent);

	// draw
	void OnDraw(Renderer2D* m_2dRenderer);

	//on exit
	void OnExit(StateMachine* pMachine);

};

