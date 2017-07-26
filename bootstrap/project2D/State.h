#pragma once
#include "dyna.h"
#include "IBehaviour.h"
#include "Renderer2D.h"
using namespace aie;

class StateMachine;
class Agent;

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
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent) = 0;
	
	//virtual draw
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	
	//virtual on exit
	virtual void OnExit(StateMachine* pMachine) = 0;

protected:
	dynamArray<IBehaviour*> m_pBehaviourList;
};

