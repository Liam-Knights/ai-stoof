#include "DecisionTree.h"
#include "DecisionButtonPressed.h"
#include "DecisionNothingPressed.h"
#include "DecisionPrint.h"


DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();

	m_pRoot->m_pTrueDecision = new DecisionPrint();
	m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
}


DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pTrueDecision;
	delete m_pRoot->m_pFalseDecision;
	delete m_pRoot;
}

void DecisionTree::Update(entity* pEntity, float fDeltaTime)
{
	m_pRoot->DecisionMaking(pEntity, fDeltaTime);
}