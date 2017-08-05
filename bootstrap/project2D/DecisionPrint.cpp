#include "DecisionPrint.h"
#include <iostream>

using namespace std;

/*
	constructor for Decision print
	sets the timer to start at 0
*/
DecisionPrint::DecisionPrint()
{
	m_fTimer = 0.0f;
}

/*
	destructor for decision print
	Virtual
*/
DecisionPrint::~DecisionPrint()
{
}

/*
	dicision making function for dicision print
	adds DelataTime to the timer
	clears the screen 
	prints out how long space has been pressed
*/
void DecisionPrint::DecisionMaking(entity* pEntity, float fDeltaTime)
{
	m_fTimer += fDeltaTime;
	system("cls");
	cout << "space has been pressed for " << m_fTimer << "seconds \n";
}