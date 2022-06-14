/*

	 Custom Vector
	 Copyright © 2022 Sergey

	 Desc File: Custom vector class

*/

#ifndef __vector__h
#define __vector__h
#pragma once

#include <assert.h>

#define ERROR_PLACE -1

template<class T>
class Vector
{
public:
	// Constructor
	Vector( );

	// Destructor
	~Vector( );

	// Add to back
	void AddToBack( const T& element );

	// Add to front
	void AddToFront( const  T& element );

	// Get Size
	int size( );

	// Check, empty vector or not
	bool isEmpty( );

	// Find by value 
	bool FindVal( T val );
	bool FindVal( T val, int& place );

	// Get element
	T GetFirstElement( );
	T GetLastElement( );

	// Remove 
	void Remove( int id );

	// Clear all vector
	void ClearAll( );

	// Operators
	T& operator[]( int id );

protected:
	// Check size
	void CheckSize( );

	// Allocate memory for data
	void Allocate( int iSize );

private:
	T* m_data;
	int m_iSize;
	int m_iReserveSize;
};

/*
   Constructor
*/
template<class T>
inline Vector<T>::Vector( )
{
	m_data = 0;
	m_iSize = 0;
	m_iReserveSize = 0;
}

/*
   Destructor
*/
template<class T>
inline Vector<T>::~Vector( )
{
	m_data = 0;
	m_iSize = 0;
	m_iReserveSize = 0;
}

/*
   Add item to tail
*/
template<class T>
inline void Vector<T>::AddToBack( const T& element )
{
	CheckSize( );

	// Add To tail
	m_data[ m_iSize ] = element;
	m_iSize++;
}

/*
   Add item to front
*/
template<class T>
inline void Vector<T>::AddToFront( const T& element )
{
	m_iSize++;

	// Shift elements
	int size = m_iSize - 1;
	if ( size > 0 )
	{
		int pos = 1;
		memmove( &m_data[ pos ], &m_data[ 0 ], size * sizeof( T ) );
	}

	// Add
	m_data[ 0 ] = element;
}

/*
   Get vector size
*/
template<class T>
inline int Vector<T>::size( )
{
	return m_iSize;
}

/*
   Check, empty vector or not
*/
template<class T>
inline bool Vector<T>::isEmpty( )
{
	return m_iSize == 0;
}

/*
   Find Value in vector
*/
template<class T>
inline bool Vector<T>::FindVal( T val )
{
	for ( int i = 0; i < m_iSize; i++ )
	{
		if ( val == m_data[ i ] )
			return true;
	}

	return false;
}

/*
   Find Value in vector and get place
*/
template<class T>
inline bool Vector<T>::FindVal( T val, int& place )
{
	for ( int i = 0; i < m_iSize; i++ )
	{
		if ( val == m_data[ i ] )
		{
			place = i;
			return true;
		}
	}

	place = ERROR_PLACE;
	return false;
}

/*
   Call destructor if exist
*/
template<class T>
void CallDestructor( T* data )
{
	data->~T( );
}

template<class T>
inline void Vector<T>::ClearAll( )
{
	delete[ ] m_data;

	m_iSize = 0;
	m_iReserveSize = 0;
}

/*
   Get first element in vector
*/
template<class T>
inline T Vector<T>::GetFirstElement( )
{
	return m_data[ 0 ];
}

/*
   Get last element in vector
*/
template<class T>
inline T Vector<T>::GetLastElement( )
{
	return m_data[ m_iSize - 1 ];
}



/*
   Remove element by ID
*/
template<class T>
inline void Vector<T>::Remove( int id )
{
	// Call destructor if exist ( for classes )
	CallDestructor( &m_data[ id ] );

	// Move element to tail
	int size = m_iSize - id - 1;
	if ( size > 0 )
	{
		memmove( &m_data[ id ], &m_data[ id + 1 ], size * sizeof( T ) );
	}

	// Decrease size
	m_iSize--;
}

/*
   operator[]
*/
template<class T>
inline T& Vector<T>::operator[]( int id )
{
	assert( ( unsigned )id < ( unsigned )m_iSize );

	return m_data[ id ];
}

/*
   Check size, if override or empty,then allocate memory
*/
template<class T>
inline void Vector<T>::CheckSize( )
{
	if ( isEmpty( ) )
		Allocate( 4 );
	else if ( m_iSize == m_iReserveSize )
		Allocate( m_iReserveSize * 4 );
}

/*
   Allocate
*/
template<class T>
inline void Vector<T>::Allocate( int iSize )
{
	T* temp = new T[ iSize ];

	// Copy old data
	for ( int i = 0; i < m_iSize; i++ )
	{
		temp[ i ] = m_data[ i ];
	}

	m_data = temp;

	// Update reserv
	m_iReserveSize = iSize;
}


#endif // !__vector__h

