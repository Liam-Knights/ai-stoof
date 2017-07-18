#pragma once
#include "dyna.h"

template <typename T>
class Stack
{
public:

	Stack(){}
	~Stack(){}

	bool empty()
	{
		return s.empty();
	}
	
	int size()
	{
		return s.Size();
	}

	void push(T value)
	{
		s.pushBack(value);
	}

	T pop()
	{
		return s.popBack();
	}

	T top()
	{
		return s.back();
	}

	T SecondLast()
	{
		return s.SecondLast();
	}

	void Clear()
	{
		s.Clear();
	}


	dynamArray<T> s;

};