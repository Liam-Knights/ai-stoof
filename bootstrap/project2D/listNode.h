#pragma once


template <typename t>
class listNode
{

public:
	//default constructor
	listNode() {};
	//default destructor
	~listNode() {};

	t data;
	listNode* next;
	listNode* prev;
};

