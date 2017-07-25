#include "entity.h"



entity::entity()
{
	//setting the variable to false
	// so it doesnt spawn any objects or anything else untill ready
	m_bActive = false;
}


entity::~entity()
{
	//defualt destructor
}

void entity::setActive(bool bActive)
{
	//when function gets called sets m_bActive to bActive
	//so that its equal to active
	m_bActive = bActive;
}

bool entity::getActive()
{
	//returns m_bActive
	return m_bActive;
}

void entity::updateGlobalTransform(float fDeltaTime)
{
	//empty base function for the update of the program
}
void entity::Draw(aie::Renderer2D* m_2dRender)
{
	//empty bas function for the drawing of the program
}