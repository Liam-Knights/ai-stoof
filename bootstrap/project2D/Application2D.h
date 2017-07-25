#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"
#include "GridNode.h"
#include "DecisionTree.h"
#include "player.h"
#include "BehaveNode.h"
#include "AiBehhaviour.h"

class DecisionTree;
class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	AiBehhaviour*			m_Behave;
	Player*				m_player;
	DecisionTree*		m_DecisionTree;
	GridNode**			m_ppGrid;

	float m_cameraX, m_cameraY;
	float m_timer;
};