#include "DecisionTree.h"
#include "DecisionButtonPressed.h"
#include "DecisionNothingPressed.h"
#include "DecisionPrint.h"

/*
	constructor for Decision tree
	should have diferent names probably
	creates new button pressed 
	creates new decision Print
	creates new Decision nothing pressed
*/
DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();

	m_pRoot->m_pTrueDecision = new DecisionPrint();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}

/*
	destructor for decision tree
	deletes everything made in constructor
*/
DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot;
}

/*
	update function
	calls the decision making function from decision question
*/
void DecisionTree::Update(entity* pEntity, float fDeltaTime)
{
	m_pRoot->DecisionMaking(pEntity, fDeltaTime);
}