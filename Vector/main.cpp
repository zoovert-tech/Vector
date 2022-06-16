/*

	 Custom Vector
	 Copyright © 2022 Sergey

	 Desc File: cpp file for test vector

*/

#include <iostream>

#include "Vector.h"

int main()
{
	Vector<const char*>swapTest;
	
	swapTest.AddToBack( "This" );
	swapTest.AddToBack( "string" );
	swapTest.AddToBack( "for" );
	swapTest.AddToBack( "test" );
	swapTest.AddToBack( "swap" );

	// Before
	for ( int i = 0; i < swapTest.size( ); i++ )
	{
		printf( "%s ", swapTest[ i ] );
	}

	swapTest.Swap( swapTest.size( ) - 1, 1 );
	printf( "\n" );

	// After
	for ( int i = 0; i < swapTest.size( ); i++ )
	{
		printf( "%s ", swapTest[ i ] );
	}

	return 0;
}

