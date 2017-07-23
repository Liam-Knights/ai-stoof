#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;

class State
{
public:
	//defualt constructor
	State();
	//default destructor
	~State();
	
	//virtual on enter
	virtual void OnEnter(StateMachine* pMachine) = 0;
	
	//virtual on update
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine) = 0;
	
	//virtual draw
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	
	//virtual on exit
	virtual void OnExit(StateMachine* pMachine) = 0;

};

