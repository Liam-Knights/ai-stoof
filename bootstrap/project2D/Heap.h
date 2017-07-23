#pragma once
#include "dyna.h"
#include "A-StarStruct.h"

class heap
{
public:
	heap(){};
	~heap(){};

	void push(AStarNode* data)
	{
		//add data to the end of the array
		m_data.pushBack(data);

		//loop through and swap if parent is smaller
		int current = m_data.Size() - 1;
		while (true)
		{
			int parent = GetParentIndex(current);
			if (m_data[current]->m_nFscore < m_data[parent]->m_nFscore)
			{
				AStarNode* temp = m_data[current];
				m_data[current] = m_data[parent];
				m_data[parent] = temp;
				current = parent;
			}
			else 
			{
				break;
			}
			//repeat until no more is required from loop
		}
	}

	AStarNode* pop()
	{
		AStarNode* result = m_data[0];
		
		//replace first variable with last
		int last = m_data.Size() - 1;
		m_data[0] = m_data[last];
		int current = 0;
		
		while (true)
		{
			int child0 = GetChildIndex(current, 1);
			if (child0 > last)
			{
				break;
			}

			int child1 = GetChildIndex(current, 2);
			int SmallerChild = child0;
			if (child1 <= last && m_data[child1]->m_nFscore < m_data[child0]->m_nFscore)
			{
				SmallerChild = child1;
			}

			if (m_data[SmallerChild]->m_nFscore < m_data[current]->m_nFscore)
			{
				AStarNode* temp = m_data[current];
				m_data[current] = m_data[SmallerChild];
				m_data[SmallerChild] = temp;
				current = SmallerChild;

			}

			else
			{
				break;
			}
			m_data.popBack();
			return result;
		}
	}

	void clear()
	{
		m_data.clear();
	}

	int GetSize()
	{
		return (int)m_data.Size();
	}

	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1) / 2;
	}
	
	int GetChildIndex(int ParentIndex, int WhichIndex)
	{
		return (2 * ParentIndex) + WhichIndex;
	}

	bool contains(AStarNode* pData)
	{
		for (int i = 0; i < m_data.Size(); ++i)
		{
			if (m_data[i] == pData)
			{
				return true;
			}
		}
		return false;
	}

private:
	dynamArray<AStarNode*> m_data;
};
