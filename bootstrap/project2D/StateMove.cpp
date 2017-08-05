#include "StateMove.h"
#include "seek.h"
#include "flee.h"
#include "Agent.h"

/*
	state purse constructor
	pushes both the seek and flee behaviours
	and sets the weighting for seek to be stronger then the one for flee
*/
StateMove::StateMove()
{
	m_pBehaviourList.pushBack(new seek(0.75f));
	m_pBehaviourList.pushBack(new flee(0.20f));
}

/*
	destructor
	for loop that deletes the new pursue made in the constructor
*/
StateMove::~StateMove()
{
	for (unsigned int i = 0; i < m_pBehaviourList.Size(); ++i)
	{
		delete m_pBehaviourList[i];
	}
}

//on enter
void StateMove::OnEnter(StateMachine* pMachine)
{

}

/*
on update function
this decides both the speed and velocity
it then sets the position of the seek and flee agent which is the same agent
*/
void StateMove::OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent)

{
	Vector2 v2force;
	for (unsigned int i = 0; i < m_pBehaviourList.Size(); ++i)
	{
		Vector2 currentForce = m_pBehaviourList[i]->calculate(pAgent, fDeltaTime);
		currentForce = currentForce * m_pBehaviourList[i]->m_fWeighting;

		v2force = v2force + currentForce;

		float fMag = v2force.magnitude();
		if (fMag > 10.0f)
		{
			v2force.normalise();
			v2force = v2force * 10.0f;
			break;
		}
	}
	pAgent->setPos(pAgent->getPos() + v2force);
}

// draw
void StateMove::OnDraw(Renderer2D* m_2dRenderer)
{

}

//on exit
void StateMove::OnExit(StateMachine* pMachine)
{

}