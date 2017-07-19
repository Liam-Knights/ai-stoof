#pragma once
#include "Heap.h"
#include "A-StarStruct.h"

class Astar
{
public:
	Astar(int MaxNodes);
	~Astar();

	bool CalcPath(AStarNode* pStart, AStarNode* pEnd, dynamArray<AStarNode*>* FinPath);
	int calcHeuristic(AStarNode* pNode, AStarNode* pEnd);

private:

	heap m_OpenNode;
	bool* m_ClosedNode;
	int m_nMaxNode;

};

