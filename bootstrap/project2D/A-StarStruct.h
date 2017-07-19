#pragma once
#include "dyna.h"

struct AStarNode;

struct AStarEdge
{
	AStarNode* m_pEndNode;

	int m_nCost;
};

struct AStarNode
{
	

	AStarNode()
	{
		m_prev = nullptr;

		m_nFscore = 0;
		m_nGScore = 0;
		m_nHScore = 0; 
		m_nBlocked = false;
	}

	int m_nGScore;
	int m_nHScore;
	int m_nFscore;

	bool m_nBlocked;

	AStarNode* m_prev;
	dynamArray<AStarEdge*> AdjacentNode;
};