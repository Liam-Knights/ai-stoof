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
	/*
	player 2 constructor
	sets m_ppGrid to pGrid
	creates a new astar node
	GRIDSIZE in defines
	setts next node
	sets the going back variable to flase untill it is needed later on
	*/
	player2(GridNode** pGrid);
	
	/*
	destructor
	deletes the astar made in the constructor
	*/
	~player2();

	/*
	update function
	calls the calculate function and sets the path to find

	when reaches end of path sets going back function to true
	when going back is true the node starts going in the oposite direction
	
	untill it reaches the first node which sets going back to false
	it continues to do this over and over
	*/
	void Update(float fDeltaTime);
	
	/*
	draw function
	draws the nodes path
	draws the node
	*/
	void Draw(Renderer2D* m_pRender);

private:

	Vector2 vector2p;
	Astar* m_pAstar;
	dynamArray<AStarNode*> m_Path;
	GridNode** m_ppGrid;
	int m_nextNode;
	bool m_bGoingBack;
};

