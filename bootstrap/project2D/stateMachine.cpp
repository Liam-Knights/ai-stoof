#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"

using namespace aie;

StateMachine::StateMachine()
{
	//default
}

StateMachine::~StateMachine()
{
	//pops state
	while (m_CurrentStack.size() > 0)
		PopState();

	//deletes the state list
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float deltaTime)
{
	//returns if the state is less or equal to 0
	if (m_CurrentStack.size() <= 0)
		return;
	
	//updates the state on the stack
	m_CurrentStack.top()->OnUpdate(deltaTime, this);

}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	//returns if the state is less or equal to 0
	if (m_CurrentStack.size() <= 0)
	{
		return;
	}
	//onoff draws the backround to be visable or not
	if (onoff)
	{
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);
	}
	m_CurrentStack.top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	//pushes the state onto the next
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);

	m_CurrentStack.push(m_StateList[nStateIndex]);
	m_CurrentStack.top()->OnEnter(this);
}

void StateMachine::PopState()
{
	
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);
	
	//pops the state of the stack
	m_CurrentStack.pop();
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	//inserts a state to a specific spot
	m_StateList.insert(nStateIndex, pState);
}

void StateMachine::setBackround(bool OnOff)
{
	//sets onoff to OnOff OnOff is true
	this->onoff = OnOff;
}