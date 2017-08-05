#pragma once
#include "DecisionQestion.h"

class DecisionTree
{
public:

	/*
	constructor for Decision tree
	should have diferent names probably
	creates new button pressed
	creates new decision Print
	creates new Decision nothing pressed
	*/
	DecisionTree();

	/*
	destructor for decision tree
	deletes everything made in constructor
	*/
	virtual ~DecisionTree();

	/*
	update function
	calls the decision making function from decision question
	*/
	void Update(entity* pEntity, float fDeltaTime);

	DecisionQuestion* m_pRoot;


};