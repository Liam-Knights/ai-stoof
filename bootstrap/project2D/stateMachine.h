#pragma once
#include "Renderer2D.h"
#include "dyna.h" 
#include "State.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	//default constructor
	StateMachine();
	//destructor pops state and deletes stateList
	~StateMachine();

	//returns if there are is 0 states
	void Update(float deltaTime);

	//returns id there are 0 states
	//calls draw if onoff is true
	void Draw(Renderer2D* m_2dRenderer);

	//pushes the state onto the next one or specific one required
	void PushState(int nStateIndex);
	
	////adds a state to the list
	void AddState(int nStateIndex, State* pState);
	
	//pops a state of the stack
	void PopState();

	//sets the backround if its visable or not
	void setBackround(bool OnOff);
private:
	bool onoff = false;
	dynamArray<State*> m_StateList;
	Stack<State*> m_CurrentStack;
};