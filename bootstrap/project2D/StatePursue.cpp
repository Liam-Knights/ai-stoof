#include "StatePursue.h"
#include "Pursue.h"
#include "Agent.h"


/*
	state purse constructor
	sets m_pursue to a new Pursue
	pushes the the new pursue
*/
StatePursue::StatePursue()
{

	m_pPursue = new Pursue(1.00f);
	m_pBehaviourList.pushBack(m_pPursue);


}

/*
	destructor
	for loop that deletes the new pursue made in the constructor
*/
StatePursue::~StatePursue()
{
	for (unsigned int i = 0; i < m_pBehaviourList.Size(); ++i)
	{
		delete m_pBehaviourList[i];
	}
}

//on enter
void StatePursue::OnEnter(StateMachine* pMachine)
{

}

/*
	on update function
	this decides both the speed and velocity
	it then sets the position of the pursueing agent
*/
void StatePursue::OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent)

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
void StatePursue::OnDraw(Renderer2D* m_2dRenderer)
{

}

//on exit
void StatePursue::OnExit(StateMachine* pMachine)
{

}

/*
	set target function
	sets m_pPurse as the target Agent
*/
void StatePursue::setTarget(Agent* Target)
{
	m_pPursue->setTarget(Target);
}