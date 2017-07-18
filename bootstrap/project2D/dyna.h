#pragma once
#include <memory.h>
#include <crtdbg.h>

template <typename t>
class dynamArray
{


public:

	//constructor
	dynamArray(int size = 0) 
	{
		//setting cap to the variable entered into the function when called
		int cap = size;

		if (cap <= 0)
		{
			cap = 1;
		}


		_ASSERT(data);
		data = new t[cap];
		m_nCapacity = cap;
		m_nUsed = 0;
	}

	//destructor to delete the pointer made
	~dynamArray() 
	{
		delete[] data;
	}

	dynamArray(const dynamArray& other)
	{

		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUSed;

		_ASSERT(data);
		data = new t[m_nCapacity];
		mempcy(data, other.data, sizeof(t) * m_nCapacity);
	}
	//function to push a new variable onto the array
	void pushBack(t value)
	{
		if (m_nUsed >= m_nCapacity)
		{
			resize();
		}
		data[m_nUsed] = value;
		++m_nUsed;
	}
	//function to push a new variable onto the array
	void pushFront(t value)
	{
		insert(0, value);
	}

	//to insert variable into the array
	void insert(int index, t value)
	{
		if (index > m_nUsed)
		{
			return;
		}
		if (m_nUsed >= m_nCapacity)
		{
			resize();
		}
		for (int i = m_nUsed - 1; i >= index; --i)
		{
			data[i + 1] = data[i];
		}
		data[index] = value;
		++m_nUsed;
	}

	void resize()
	{
		
		t* newData = new t[m_nCapacity * 2];
		_ASSERT(newData);
		memcpy(newData, data, sizeof(t) * m_nCapacity);
		delete data;
		data = newData;
		m_nCapacity = m_nCapacity * 2;

	}
	//pops a variable off the back array
	t popBack()
	{
		if (m_nUsed <= 0)
			return 0;
		
		--m_nUsed;

		return data[m_nUsed + 1];
	}

	//pops a variable off a specific spot of the array
	t remove(int index)
	{
		t value = data[index];

		for (int i = index; index < m_nUsed; ++i)
		{
			data[i] = data[i + 1];
		}
		--m_nUsed;

		return value;

	}
	//pops the front variable off the array
	t popFront()
	{
		return remove(0);
	}
	//clears the entire array
	void clear()
	{
		delete data;
		m_nUsed = 0;
	}

	//shrinks the array down
	//capacity is changed to the size of the array
	void shrink()
	{

		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
		{
			nCapacity = 1;
		}
		_ASSERT(newData);
		t* newData = new t[m_nCapacity];
		memcpy(newData, data, sizeof(t) * m_nCapacity);
		delete data;
		data = newData;
		m_nCapacity = m_nCapacity;

	}

	t& operator[](const int index)
	{
		return data[index];
	}

	//returns the size of the array
	int Size()
	{
		return m_nUsed;
	}

	//reeturns the capacity in the array
	int Capacity()
	{
		return m_nCapacity;
	}

	//is the array epmty 
	//call function to test of array is empty
	bool empty()
	{
		if (m_nUsed <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	t back()
	{
		return data[m_nUsed - 1];
	}
	//aslight change used in the pause menu to give a clear backround its pretty much depth
	t SecondLast()
	{
		return data[m_nUsed - 2];
	}
private:
	dynamArray& operator= (const dynamArray& other) = default;
	dynamArray(dynamArray&& other) = default;
	dynamArray& operator= (dynamArray&& other) = default;
	
	int m_nCapacity;
	int m_nUsed;
	t* data;

};

