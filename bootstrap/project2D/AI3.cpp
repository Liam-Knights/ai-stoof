#include "AI3.h"
#include "stateMachine.h"
#include "State.h"
#include "StateMove.h"
#include "StateWonder.h"


/*
AI constructor
creates new state machine
creates new stateMove
adds State move to the stateMachine
pushes the state
sets x and y position
*/
AI3::AI3()
{
	m_pStateMachine = new StateMachine();


	m_pStateMachine->AddState(0, new StateWonder());

	m_pStateMachine->PushState(0);

	m_v2Pos.x = 600;
	m_v2Pos.y = 400;
}

/*
AI destructor
Virtual
*/
AI3::~AI3()
{
}

/*
update function
calls the updates for state machine
*/
void AI3::Update(float fDeltaTime)
{
	m_pStateMachine->Update(fDeltaTime, this);
}

/*
draw function
Draws circle
sets the circles colour
*/
void AI3::Draw(Renderer2D* Render)
{
	Render->setRenderColour(0x00FF00FF);
	Render->drawCircle(m_v2Pos.x, m_v2Pos.y, 27.0f);
	Render->setRenderColour(0x00FF00FF);

}