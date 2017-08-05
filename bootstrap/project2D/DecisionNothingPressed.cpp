#include "DecisionNothingPressed.h"
#include <iostream>

using namespace std;

/*
	constructor for Decision nothing pressed
*/
DecisionNothingPressed::DecisionNothingPressed()
{
}

/*
	destructor for decision nothing pressed
	Virtual
*/
DecisionNothingPressed::~DecisionNothingPressed()
{
}

/*
	dicision making function for dicision nothing pressed
	clears the screen
	prints out cat
*/
void DecisionNothingPressed::DecisionMaking(entity* pEntity, float fDeltaTime)
{
	system("cls");
	cout << "cat \n";
}