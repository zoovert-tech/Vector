/*

	 Custom Vector
	 Copyright © 2022 Sergey

	 Desc File: cpp file for test vector

*/

#include <iostream>

#include "Vector.h"

class CTest
{
public:
	CTest( )
	{
		m_iIndex = 100;
	}

	~CTest( )
	{
		m_iIndex = -1;
	}

	int GetIndex( )
	{
		return m_iIndex;
	}

private:
	int m_iIndex;
};

int main()
{
	Vector<CTest>w;
	w.AddToBack( CTest( ) );
	
	int index = w.GetLastElement( ).GetIndex( );

	w.Remove( 0 );

	index = w.GetFirstElement( ).GetIndex( );

	return 0;
}

