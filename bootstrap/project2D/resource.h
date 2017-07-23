#pragma once
#include <string.h>
#include <crtdbg.h>

template <typename t>
class resource
{
public:
	//constructor creates a string this is used to get the text on screen
	resource(char* szFileName, int size)
	{
		int length = strlen(szFileName);
		_ASSERT(m_szFileName);
		m_szFileName = new char[length + 1];
		strcpy_s(m_szFileName, length + 1, szFileName);

		_ASSERT(m_Data);
		m_Data = new t(szFileName, size);
	}
	//destructor deletes all created pointers
	~resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	t* m_Data;

};

