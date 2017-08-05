#pragma once
#include "State.h"


class StateWonder : public State
{
public:
	
	/*
	should probably be named stateWander
	constructor for state wonder
	pushes the wonder state
	*/
	StateWonder();

	/*
	destructor for state wonder
	for loop that deletes all the new wonders that get created
	*/
	~StateWonder();

	//on enter
	void OnEnter(StateMachine* pMachine);

	/*
	on update function
	this decides both the speed and velocity
	it then sets the position of the wandering agent
	*/
	void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent);

	// draw
	void OnDraw(Renderer2D* m_2dRenderer);

	//on exit
	void OnExit(StateMachine* pMachine);
};

