#pragma once

class BehaveNode;

class AiBehhaviour
{
public:
	
	/*
	Ai Behhaviour constructor
	creates new selecter
	creates two new sequence files
	creates new example action
	creates new example question
	pushes them all in certain order
	*/
	AiBehhaviour();

	/*
	Ai Behhaviour destructor
	deletes the selecter
	*/
	~AiBehhaviour();

	/*
	ai behhaviour update
	calls execute
	*/
	void Update(float fDeltaTIme);

	BehaveNode* m_pRoot;
};

