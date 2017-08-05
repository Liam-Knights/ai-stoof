#include "player2.h"
#include "Defines.h"


/*
	player 2 constructor
	sets m_ppGrid to pGrid
	creates a new astar node
	GRIDSIZE in defines
	setts next node
	sets the going back variable to flase untill it is needed later on
*/
player2::player2(GridNode** pGrid)
{
	m_ppGrid = pGrid;

	m_pAstar = new Astar(GRIDSIZE * GRIDSIZE);
	m_nextNode = 0;
	m_bGoingBack = false;
}

/*
	destructor
	deletes the astar made in the constructor
*/
player2::~player2()
{
	delete m_pAstar;
}

/*
	update function
	calls the calculate function and sets the path to find

	when reaches end of path sets going back function to true
	when going back is true the node starts going in the oposite direction
	
	untill it reaches the first node which sets going back to false
	it continues to do this over and over
*/
void player2::Update(float fDeltaTime)
{
	m_Path.clear();

	m_pAstar->CalcPath(m_ppGrid[91], m_ppGrid[8], &m_Path);
	if (m_nextNode >= m_Path.Size() - 1)
	{
		m_bGoingBack = true;
	}

	if (m_nextNode <= 0)
	{
		m_bGoingBack = false;
	}

	Vector2 dest = ((GridNode*)m_Path[m_nextNode])->m_vectorPos;
	Vector2 dir = dest - vector2p;
	dir.normalise();
	vector2p = vector2p + dir * 1000.0f * fDeltaTime;
	Vector2 dist = dest - vector2p;
	float fDist = dist.magnitude();
	if (fDist < 10)
	{
		if (m_bGoingBack)
		{
			--m_nextNode;
		}
		else
		{
			++m_nextNode;
		}
	}
}

/*
	draw function
	draws the nodes path
	draws the node
*/
void player2::Draw(Renderer2D* m_pRender)
{
	for (size_t i = 0; i < m_Path.Size(); ++i)
	{
		GridNode* otherNode = ((GridNode*)m_Path[i]);

		m_pRender->setRenderColour(0x00FFFFFF);
		m_pRender->drawBox(otherNode->m_vectorPos.x, otherNode->m_vectorPos.y, NODESIZE / 2, NODESIZE / 2);
		m_pRender->setRenderColour(0xFFFFFFFF);
	}

	m_pRender->setRenderColour(0xAA00FFFF);
	m_pRender->drawBox(vector2p.x, vector2p.y, NODESIZE / 2, NODESIZE / 2);
	m_pRender->setRenderColour(0xFFFFFFFF);
}