#pragma once
#include "DecisionQestion.h"

class DecisionTree
{
public:
	DecisionTree();
	virtual ~DecisionTree();
	void Update(entity* pEntity, float fDeltaTime);

	DecisionQuestion* m_pRoot;


};