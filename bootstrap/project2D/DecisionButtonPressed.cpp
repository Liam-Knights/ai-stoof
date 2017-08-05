#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;

/*
	constructor for decision button pressed
*/
DecisionButtonPressed::DecisionButtonPressed()
{
}

/*
	destructor for Decision button pressed
	Virtual
*/
DecisionButtonPressed::~DecisionButtonPressed()
{
}

/*
	Dicision making function
	if space is pressed run the dicision maing function from the bas class
	if not the same but m_pfalseDecion is used instead of true
*/
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
