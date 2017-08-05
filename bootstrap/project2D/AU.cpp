#include "AU.h"
#include "stateMachine.h"
#include "State.h"
#include "StateMove.h"

/*
	AI constructor
	creates new state machine
	creates new stateMove
	adds State move to the stateMachine
	pushes the state
*/
AI::AI()
{
	m_pStateMachine = new StateMachine();


	m_pStateMachine->AddState(0, new StateMove());

	m_pStateMachine->PushState(0);
}

/*
	AI destructor 
	Virtual
*/
AI::~AI()
{
}

/*
	update function
	calls the updates for state machine
*/
void AI::Update(float fDeltaTime)
{
	m_pStateMachine->Update(fDeltaTime, this);
}

/*
	draw function
	Draws circle
	sets the circles colour
*/
void AI::Draw(Renderer2D* Render)
{
	Render->setRenderColour(0xAA00FFFF);
	Render->drawCircle(m_v2Pos.x, m_v2Pos.y, 20.0f);
	Render->setRenderColour(0xAA00FFFF);
	
}