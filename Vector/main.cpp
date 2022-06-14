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
		m_iId = 1;
		m_iVersion = 0x23112;
		m_szName = "AddMeToVectorClass";
	}

	~AddMeInVector( )
	{
		m_iId = 0;
		m_iVersion = 0;
		m_szName = 0;
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
	Vector<long long>lg;
	lg.AddToBack( 99999999999999999 );
	lg.AddToBack( 28364718274182 );
	lg.AddToBack( 61236123127312 );

	lg.AddToBack( 17263237612637 );

	// is
	if ( lg.isEmpty( ) )
		return EXIT_FAILURE;

	printf( "%lld\n", lg[ 0 ] );
	printf( "%lld\n", lg[ 1 ] );
	printf( "%lld\n", lg[ 2 ] );
	printf( "%lld\n", lg[ 3 ] );

	// Check assert
	//printf( "%lld\n", lg[ 4 ] );
}

