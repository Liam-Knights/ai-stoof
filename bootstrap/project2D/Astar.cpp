#include "Astar.h"
#include "Defines.h"
#include <memory.h>
#include "GridNode.h"
#include <math.h>


Astar::Astar(int MaxNodes)
{
	m_ClosedNode = new bool[MaxNodes];
	m_nMaxNode = MaxNodes;

}


Astar::~Astar()
{
	delete[] m_ClosedNode;
}

bool Astar::CalcPath(AStarNode* pStart, AStarNode* pEnd, dynamArray<AStarNode*>* FinPath)
{
	m_OpenNode.clear();
	memset(m_ClosedNode, false, m_nMaxNode * sizeof(bool));
	pStart->m_nGScore = 0;
	pStart->m_nHScore = calcHeuristic(pStart, pEnd);
	pStart->m_nFscore = pStart->m_nGScore + pStart->m_nHScore;
	pStart->m_prev = nullptr;

	m_OpenNode.push(pStart);

	//While there are still nodes in the open list
	while (m_OpenNode.GetSize() > 0)
	{
		//Get the node from the open list with the lowest F Score, we'll call that currentNode.
		AStarNode* currentNode;
		//Remove currentNode from the open list.
		currentNode = m_OpenNode.pop();
		//Add currentNode to the closed list.
		m_ClosedNode[currentNode->m_nIndex] = true;

		//if currentNode is the end node, we are finished.
		if (currentNode == pEnd)
		{
			//Build path (remember it is backwards so we need to fix that)
			AStarNode* pNode = pEnd;

			while (pNode)
			{
				FinPath->pushFront(pNode);
				pNode = pNode->m_prev;
				//Return that we found a valid path.
				
			}
			return true;
		}
			
		//Loop through all of currentNode's neighbours
		for (int i = 0; i < currentNode->AdjacentNode.Size(); ++i)
		{
			AStarNode* m_pNeibours;
			m_pNeibours = currentNode->AdjacentNode[i]->m_pEndNode;

			if (m_pNeibours->m_nBlocked)
				continue;

			//Skip neighbours that are already in the closed list.
			if (m_ClosedNode[m_pNeibours->m_nIndex] == true)
			{
				continue;
			}
			int nCost = currentNode->AdjacentNode[i]->m_nCost;
			//if neighbour is already in open list...
			if (m_OpenNode.contains(m_pNeibours))
			{
					
				//Check if this current path is better than old path (lower F Score).
				if (currentNode->m_nFscore + nCost < m_pNeibours->m_nFscore)
				{	
					//Update G Score.
					m_pNeibours->m_nGScore = currentNode->m_nGScore + nCost;
					//Update F Score.
					m_pNeibours->m_nFscore = m_pNeibours->m_nHScore + m_pNeibours->m_nGScore;
					//Update Prev node pointer.
					m_pNeibours->m_prev = currentNode;
				}
			}
			//else (neighbour not in open list)
			else
			{
				//Calculate G Score.
				m_pNeibours->m_nGScore = currentNode->m_nGScore + nCost;
				//Calculate H Score.
				m_pNeibours->m_nHScore = calcHeuristic(m_pNeibours, pEnd);
				//Calculate F Score.
				m_pNeibours->m_nFscore = m_pNeibours->m_nGScore + m_pNeibours->m_nHScore;
				//Set Prev node pointer.
				m_pNeibours->m_prev = currentNode;
				//Add neighbour to open list.
				m_OpenNode.push(m_pNeibours);
			}
		}
	}

	//No path found if we got to here, so return false.
	return false;

}

int Astar::calcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{
	int nDifX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int nDify = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;
	
	nDifX = abs(nDifX);
	nDify = abs(nDify);
	if (nDifX > nDify)
	{
		return (14 * nDify + 10 * (nDifX - nDify));
	}
	else
	{
		return (14 * nDifX + 10 * (nDify - nDifX));
	}
}