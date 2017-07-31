#pragma once
#include "Vector2.h"
#include "entity.h"
#include "Astar.h"
#include "Renderer2D.h"
#include "GridNode.h"

using namespace aie;
class player2 : public entity
{
public:
	player2(GridNode** pGrid);
	~player2();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* m_pRender);

private:

	Vector2 vector2p;
	Astar* m_pAstar;
	dynamArray<AStarNode*> m_Path;
	GridNode** m_ppGrid;
	int m_nextNode;
	bool m_bGoingBack;
};

