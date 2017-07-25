#pragma once
#include "Renderer2D.h"
class entity
{
public:
	//sets the m_bActive variable
	//other then that a basic constructor 
	entity();

//	default destructor
	~entity();

	//virtual function just a base for other clases that use entity
	//set active changes m_bactive
	virtual void setActive(bool bActive);

	//virtual function just a base for other clases that use entity
	//returns m_bActive
	virtual bool getActive();

	//virtual function just a base for other clases that use entity
	//function made to update the entire program but only virtual it is empty
	virtual void updateGlobalTransform(float fDeltaTime);

	//virtual function
	// a basic draw function it is empty
	virtual void Draw(aie::Renderer2D* m_2dRender);

private:
	bool m_bActive;

};

