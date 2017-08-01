#include "AI2.h"
#include "stateMachine.h"
#include "State.h"
#include "StatePursue.h"

AI2::AI2()
{
	m_pStateMachine = new StateMachine();
	m_pStatePursue = new StatePursue();

	m_pStateMachine->AddState(0, m_pStatePursue);

	m_pStateMachine->PushState(0);
}


AI2::~AI2()
{
}

void AI2::Update(float fDeltaTime)
{
	m_pStateMachine->Update(fDeltaTime, this);
}

void AI2::Draw(Renderer2D* Render)
{
	Render->setRenderColour(0x0000FFFF);
	Render->drawCircle(m_v2Pos.x, m_v2Pos.y, 40.0f);
	Render->setRenderColour(0x0000FFFF);

}

void AI2::setTarget(Agent* Target)
{
	m_pStatePursue->setTarget(Target);
}