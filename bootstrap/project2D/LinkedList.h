#pragma once
#include "listNode.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;
template <typename t>
class LinkedList
{
public:
	//constructorthat sets the start and end values
	LinkedList() 
	{
		_ASSERT(start);
		start = new listNode<t>();
		_ASSERT(end);
		end = new listNode<t>();
		start->next = end;
		start->prev = nullptr;
		end->next = nullptr;
		end->prev = start;

	}
	//destructor deletes the start and end pointers
	~LinkedList() 
	{
		delete start;
		delete end;
	}

	//inserts a value inbetween specific variables
	void insert(t value, listNode<t>* prev, listNode<t>* next)
	{
		_ASSERT(N1);
		listNode<t>* N1 = new listNode<t>();
		N1->data = value;
		N1->next = next;
		prev->next = N1;
		next->prev = N1;
		N1->prev = prev;
		++nCount;
	}

	//inserts a variable at the end
	void pushback(t value)
	{
		insert(value, end->prev, end);
	}

	//inserts a variiable at the start
	void pushFront(t value)
	{
		insert(value, start, start->next);
	}


	void IndexInsert(int index, t values)
	{
		listNode<t>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "invalaid" << endl;
				return value;
			}
			current = current->next;
		}
		insert(value, current, current->next)
	}

	// shows the first variable or f the list is empty
	t first()
	{
		if (start->next == end)
		{
			cout << "list is empty \n";
			return defualt;
		}
		else
		{
			t value = start->next->data;
			return value;
		}
	}

	//shows the last variable or if the list is empty
	t last()
	{
		if (start->next == end)
		{
			cout << "list is empty \n";
			return defualt;
		}
		else
		{
			t value = end->prev->data;
			return value;
		}

	}
	//shows the size of the array
	int size()
	{
		return nCount;
	}

	//erases a variable in the array
	void erase(int index)
	{
		listNode<t>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			current = current->next;
		}
		if (current == start || current == end)
		{
			cout << "Cannot delete start and end!" << endl;
			return;
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
	}

	//removes a specific variable
	void remove(t value)
	{
		listNode<t>* temp = nullptr;
		listNode<t>* current = start;
		while (current->next != end)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			if (current->data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				current = temp;
			}
			current = current->next;
		}
	}

	//pops a variable of the front
	t popFront()
	{
		listNode<t>* n = start->next;
		t temp = n->data;
		if (n != end)
		{


			n->next->prev = start;
			start->next = n->next;

			delete n;
			return temp;
			--nCount;
		}
		else
			return defualt;
	}

	//pops a variable off the end of the array
	t popback()
	{
		listNode<t>* n = end->prev;
		t temp = n->data;
		if (n != end)
		{

			n->prev->next = end;
			end->prev = n->prev

				delete n;
			return temp;
			--nCount
		}
		else
		{
			return defualt
		}
	}

	//checks if the array is empty
	bool empty()
	{
		if (start->next == end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//clears the array
	void clear()
	{
		while (start-> != end)
		{
			popback();
		}
	}

private:
	int nCount = 0;
	listNode<t>* start;
	listNode<t>* end;
	t defualt;
};

