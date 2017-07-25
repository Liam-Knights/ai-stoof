#include "AiBehhaviour.h"
#include "Selecter].h"
#include "Sequence.h"
#include "BehaveNode.h"
#include "ExampleAction.h"
#include "ExampleQuestion.h"

AiBehhaviour::AiBehhaviour()
{

	m_pRoot = new Selecter();
	ComppositeNode* pFirst = new Sequence();
	ComppositeNode* pSecond = new Sequence();


	BehaveNode*  pSecondSecond = new ExampleAction("Q is pressed");
	BehaveNode* pFirstSecond  = new ExampleQuestion();


	((ComppositeNode*)m_pRoot)->children.pushBack(pFirst);
	((ComppositeNode*)m_pRoot)->children.pushBack(pSecond);

	((ComppositeNode*)pFirst)->children.pushBack(pFirstSecond);
	((ComppositeNode*)pFirst)->children.pushBack(pSecondSecond);
}


AiBehhaviour::~AiBehhaviour()
{
	delete m_pRoot;
}

void AiBehhaviour::Update(float fDeltaTIme)
{
	m_pRoot->Execute();
}
