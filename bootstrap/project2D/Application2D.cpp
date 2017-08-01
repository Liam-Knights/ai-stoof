#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "resourceManag.h"
#include "A-StarStruct.h"
#include "GridNode.h"
#include "Defines.h"
#include <crtdbg.h>
#include "AU.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{

	m_2dRenderer = new Renderer2D();
	_ASSERT(m_2dRenderer);

	m_DecisionTree = new DecisionTree;
	m_Behave = new AiBehhaviour;

	m_Ai = new AI;
	m_Ai2 = new AI2;
	m_Ai2->setTarget(m_Ai);

	resourceManag<Font>::create();


	m_ppGrid = new GridNode*[GRIDSIZE * GRIDSIZE];
	_ASSERT(m_ppGrid);

	for (int x = 0; x < GRIDSIZE; ++x)
	{
		for (int y = 0; y < GRIDSIZE; ++y)
		{
			int index = (y * GRIDSIZE) + x;

			Vector2 pos(x * NODESIZE, y * NODESIZE);
			m_ppGrid[index] = new GridNode(pos, index, x, y);

			if (x % 3 == 0 && y != 5)
			{
				m_ppGrid[index]->m_nBlocked = true;
			}
		}
	}

	for (int x = 0; x < GRIDSIZE; ++x)
	{
		for (int y = 0; y < GRIDSIZE; ++y)
		{
			int index = (y * GRIDSIZE) + x;

			GridNode* currentNode = m_ppGrid[index];
			// -------------
			// |   | 3 |   |
			// -------------
			// | 0 | C | 2 |
			// -------------
			// |   | 1 |   |
			// -------------
			// Adjacent Nodes
			for (int a = 0; a < 4; ++a)
			{
				int localX = x;
				int localY = y;

				if (a % 2 == 0)
				{
					localX += a - 1;
				}
				else
				{
					localY += a - 2;
				}

				if (localX < 0 || localX >= GRIDSIZE)
					continue;

				if (localY < 0 || localY >= GRIDSIZE)
					continue;


				int localIndex = (localY * GRIDSIZE) + localX;
				GridNode* AdNode = m_ppGrid[localIndex];

				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = AdNode;
				pEdge->m_nCost = 10;

				currentNode->AdjacentNode.pushBack(pEdge);
			}

			// Diagonal Nodes
			for (int d = 0; d < 4; ++d)
			{
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}
				else
				{
					localX += d - 2;
					localY -= d - 2;
				}

				if (localX < 0 || localX >= GRIDSIZE)
					continue;

				if (localY < 0 || localY >= GRIDSIZE)
					continue;


				int localIndex = (localY * GRIDSIZE) + localX;
				GridNode* AdNode = m_ppGrid[localIndex];

				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = AdNode;
				pEdge->m_nCost = 14;

				currentNode->AdjacentNode.pushBack(pEdge);
			}


		}
	}
	m_player = new Player(m_ppGrid);
	m_player2 = new player2(m_ppGrid);
	return true;
}

void Application2D::shutdown() 
{
	for (int i = 0; i < GRIDSIZE * GRIDSIZE; ++i)
	{
		delete m_ppGrid[i];
	}
	delete m_2dRenderer;
	delete m_DecisionTree;
	delete m_player;
	delete m_player2;
	delete m_Ai;
	delete m_Ai2;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	m_player->Update(deltaTime);
	m_player2->Update(deltaTime);
	m_Ai->Update(deltaTime);
	m_Ai2->Update(deltaTime);
	m_DecisionTree->Update(nullptr, deltaTime);
	m_Behave->Update(deltaTime);
	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(-400 , -100);

	// begin drawing sprites
	m_2dRenderer->begin();




	for (int i = 0; i < GRIDSIZE * GRIDSIZE; ++i)
	{
		float x = m_ppGrid[i]->m_vectorPos.x;
		float y = m_ppGrid[i]->m_vectorPos.y;

		if (m_ppGrid[i]->m_nBlocked)
		{
			m_2dRenderer->setRenderColour(0xAAAAAAAA);
		}
		else
		{
			m_2dRenderer->setRenderColour(0xef67ddff);
		}

		m_2dRenderer->drawBox(m_ppGrid[i]->m_vectorPos.x, m_ppGrid[i]->m_vectorPos.y, NODESIZE - 2, NODESIZE - 2);


		for (int a = 0; a < m_ppGrid[i]->AdjacentNode.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->AdjacentNode[a]->m_pEndNode);

			float otherX = otherNode->m_vectorPos.x;
			float otherY = otherNode->m_vectorPos.y;
			m_2dRenderer->setRenderColour(0xFF0000FF);
			m_2dRenderer->drawLine(x, y, otherX, otherY, 2.0f);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
	}
	m_player->Draw(m_2dRenderer);
	m_player2->Draw(m_2dRenderer);
	m_Ai->Draw(m_2dRenderer);
	m_Ai2->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}