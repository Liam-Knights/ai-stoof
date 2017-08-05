#pragma once
#include "dyna.h"

struct AStarNode;

/*
	astar edge struct
	creates variables for astar
*/
struct AStarEdge
{
	AStarNode* m_pEndNode;

	int m_nCost;
};

/*
	astar node struct
	sets the g score
	sets the f score
	sets the h score
	sets the index and the blocked squares
	variable used in astar
*/
struct AStarNode
{
	AStarNode(int index)
	{
		m_prev = nullptr;

		m_nFscore = 0;
		m_nGScore = 0;
		m_nHScore = 0; 
		m_nIndex = index;
		m_nBlocked = false;
	}

	int m_nGScore;
	int m_nHScore;
	int m_nFscore;
	int m_nIndex;

	bool m_nBlocked;

	AStarNode* m_prev;
	dynamArray<AStarEdge*> AdjacentNode;
};