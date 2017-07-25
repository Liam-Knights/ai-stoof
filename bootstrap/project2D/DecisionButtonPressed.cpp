#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;
DecisionButtonPressed::DecisionButtonPressed()
{
}


DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::DecisionMaking(entity* pEntity, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_SPACE))
	{
		m_pTrueDecision->DecisionMaking(pEntity, fDeltaTime);
	}
	else
	{
		m_pFalseDecision->DecisionMaking(pEntity, fDeltaTime);
	}
}
