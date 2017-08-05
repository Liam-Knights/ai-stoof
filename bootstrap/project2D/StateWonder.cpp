#include "StateWonder.h"
#include "Wonder.h"
#include "Agent.h"

/*
	should probably be named stateWander
	constructor for state wonder
	pushes the wonder state
*/
StateWonder::StateWonder()
{
	m_pBehaviourList.pushBack(new Wonder(1.00f));
}

/*
	destructor for state wonder
	for loop that deletes all the new wonders that get created
*/
StateWonder::~StateWonder()
{
	for (unsigned int i = 0; i < m_pBehaviourList.Size(); ++i)
	{
		delete m_pBehaviourList[i];
	}
}

//on enter
void StateWonder::OnEnter(StateMachine* pMachine)
{

}

/*
	on update function
	this decides both the speed and velocity
	it then sets the position of the wandering agent
*/
void StateWonder::OnUpdate(float fDeltaTime, StateMachine* pMachine, Agent* pAgent)

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

	
	Vector2 Veloc = pAgent->getVeloc() + v2force * 100 * fDeltaTime;
	float vMag = pAgent->getVeloc().magnitude();
	if (vMag > 60.0f)
	{
		Veloc.normalise();
		Veloc = Veloc * 60.0f;
	}
	pAgent->setVeloc(Veloc);
	pAgent->setPos(pAgent->getPos() + pAgent->getVeloc() *fDeltaTime);
}

// draw
void StateWonder::OnDraw(Renderer2D* m_2dRenderer)
{

}

//on exit
void StateWonder::OnExit(StateMachine* pMachine)
{

}