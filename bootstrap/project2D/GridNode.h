#pragma once
#include "A-StarStruct.h"
#include "Vector2.h"

struct GridNode : public AStarNode
{
public:
	GridNode(Vector2 pos,int index, int nIndexX, int nIndexY):AStarNode(index)
	{
		m_vectorPos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;
	}


	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_vectorPos;
};