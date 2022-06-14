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
	void AddToBack( T element );

	// Get Size
	int size( );

	// Check, empty vector or not
	bool isEmpty( );

	// Find by value 
	bool FindVal( T val );
	bool FindVal( T val, int& place );

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
inline void Vector<T>::AddToBack( T element )
{
	CheckSize( );

	// Add To tail
	m_data[ m_iSize ] = element;
	m_iSize++;
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

