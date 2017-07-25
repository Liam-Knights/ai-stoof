#pragma once

class BehaveNode;

class AiBehhaviour
{
public:
	AiBehhaviour();
	~AiBehhaviour();

	void Update(float fDeltaTIme);

	BehaveNode* m_pRoot;
};

