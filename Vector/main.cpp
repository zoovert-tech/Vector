/*

	 Custom Vector
	 Copyright © 2022 Sergey

	 Desc File: cpp file for test vector

*/

#include <iostream>

#include "Vector.h"

typedef unsigned int uint;
class AddMeInVector // :3
{
public:
	AddMeInVector( )
	{
		m_iId = 0;
		m_iVersion = 0x23112;
		m_szName = "AddMeToVectorClass";
	}

	~AddMeInVector( )
	{
		m_iId = 0;
		m_iVersion = 0;
		m_szName = 0;

		printf( "Destructor called!\n" );
	}

	int GetID( )
	{
		return m_iId;
	}

	int GetVersion( )
	{
		return m_iVersion;
	}

	const char* GetName( )
	{
		return m_szName;
	}

	// Set
	void SetID( int newID )
	{
		m_iId = newID;
	}

	void SetVersion( uint version )
	{
		m_iVersion = version;
	}

	void SetName( const char* name )
	{
		m_szName = name;
	}

private:
	int m_iId;
	int m_iVersion;
	const char* m_szName;
};

int main()
{
	AddMeInVector add;
	Vector<AddMeInVector>classC;
	add.SetID( 1);
	add.SetName( "add 1" );
	add.SetVersion( 1 );
	classC.AddToBack( add );

	add.SetID( 2 );
	add.SetName( "add 2" );
	add.SetVersion( 2 );
	classC.AddToBack( add );

	AddMeInVector first = classC.GetFirstElement( );
	AddMeInVector last = classC.GetLastElement( );

	classC.ClearAll( );

	Vector<int>in;
	in.AddToBack( 2 );
	in.ClearAll( );

	return 0;
}

