#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

using namespace aie;
class Agent
{
public:
	/*
		agent constructor
		default
	*/
	Agent() {};

	/*
		agent destructor
		virtual
		defualt
	*/
	virtual ~Agent() {};

	/*
		update function
		virtual
	*/
	virtual void Update(float fDeltaTime) =0;
	
	/*
		draw function
		virtual
	*/
	virtual void Draw(Renderer2D* Render) =0;
	/*
		get position function
		returns m_v2pos
	*/
	Vector2 getPos() { return m_v2Pos; };

	/*
		set position function
		sets m_v2pos to v2pos
	*/
	void setPos(Vector2 v2Pos) { m_v2Pos = v2Pos; };

	/*
		get velocity function
		returns m_2velocity
	*/
	Vector2 getVeloc() { return m_2velocity; };

	/*
		set velocity function
		sets m_2velocity v2veloc
	*/
	void setVeloc(Vector2 v2Veloc) { m_2velocity = v2Veloc; };


protected:
	Vector2 m_v2Pos;
	Vector2 m_2velocity;

};
